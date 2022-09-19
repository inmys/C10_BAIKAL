/*
 * UART_Console.c
 *
 *  Created on: 24 июля 2020 г.
 *      Author: ikoml
 */
#include <fcntl.h>
#include "sys/alt_dev.h"
#include "alt_types.h"
#include "sys/alt_stdio.h"
#include "system.h"
#include "SPI_GPIO.h"
#include "io.h"
#include "altera_avalon_uart_regs.h"
#include "altera_avalon_uart.h"
#include "altera_avalon_uart_fd.h"
#include "sys/alt_driver.h"
#include "string.h"
#include "altera_avalon_spi.h"
#include "altera_avalon_uart.h"
#include "altera_avalon_uart_regs.h"
#include "sys/alt_irq.h"
#include "altera_16550_uart.h"
#include "altera_16550_uart_regs.h"


#define XMODEM_STATE_INIT (0)
#define XMODEM_STATE_S0 (1)
#define XMODEM_STATE_S1 (2)
#define XMODEM_STATE_S2 (3)
#define XMODEM_STATE_S3 (4)

#define UART_BUF_SIZE 64

#define XMODEM_TIME_1SEC (100)
void UART_Init(alt_u32);
struct{
	alt_u8 buf[UART_BUF_SIZE];
	alt_u8 idx;
	alt_u8 SPI_rxbuf[512];
	alt_u8 SPI_page[256];
	alt_u32 SPI_page_idx;
	alt_u32 SPI_address;
	alt_u32 t_idx;
	alt_u32 X_idx;
	alt_u32 bt_count;
	alt_u8 XmodemState;
	alt_u8 XmodemMode:1;
	alt_u32 TimerCnt;
	alt_u8 TryCounter;
}Uart_Cntrl;
#if 0
#define ALT_AVALON_UART_BUF_LEN 64
#define ALT_AVALON_UART_BUF_MSK (ALT_AVALON_UART_BUF_LEN-1)
typedef struct uart_state_s
{
  void*            base;            /* The base address of the device */
  alt_u32          ctrl;            /* Shadow value of the control register */
  volatile alt_u32 rx_start;        /* Start of the pending receive data */
  volatile alt_u32 rx_end;          /* End of the pending receive data */
  volatile alt_u32 tx_start;        /* Start of the pending transmit data */
  volatile alt_u32 tx_end;          /* End of the pending transmit data */
  alt_u32          flags;           /* Configuation flags */
  volatile alt_u8  rx_buf[ALT_AVALON_UART_BUF_LEN]; /* The receive buffer */
  volatile alt_u8  tx_buf[ALT_AVALON_UART_BUF_LEN]; /* The transmit buffer */
} uart_state;

uart_state UartContext;

static void altera_avalon_uart_irq(void* context, alt_u32 id);
static void altera_avalon_uart_txirq(uart_state* sp, alt_u32 status);
static void altera_avalon_uart_rxirq(uart_state* sp, alt_u32 status);

#endif

void Uart_Con_Init(){
	Uart_Cntrl.idx = 0;
	Uart_Cntrl.XmodemMode = 0;
	Uart_Cntrl.XmodemState = XMODEM_STATE_INIT;
	UART_Init(115200);
	UART_putstr("Console started...\n\r");
#if 0
	UartContext.base = (void*)UART_0_BASE;
	UartContext.rx_start = 0;        /* Start of the pending receive data */
	UartContext.rx_end = 0;          /* End of the pending receive data */
	UartContext.tx_start = 0;        /* Start of the pending transmit data */
	UartContext.tx_end = 0;          /* End of the pending transmit data */

	alt_ic_isr_register(UART_0_IRQ_INTERRUPT_CONTROLLER_ID,UART_0_IRQ,(alt_isr_func)altera_avalon_uart_irq,(void*)&UartContext,0);
	//sp->ctrl |= ALTERA_AVALON_UART_CONTROL_RRDY_MSK;
	alt_ic_irq_enabled(UART_0_IRQ_INTERRUPT_CONTROLLER_ID,UART_0_IRQ);
#endif
}

void Test_SPI();
void Xmodem_SPI();


void UART_Con_Mash(){
	alt_u8 bt;
	alt_u8 cmd_flag;
	int result;
	//ALT_DRIVER_WRITE_EXTERNS(ALT_STDOUT_DEV);
	//ALT_DRIVER_WRITE(ALT_STDOUT_DEV, test_buf, strlen(test_buf), O_NONBLOCK);
	cmd_flag = 0;
	if(Uart_Cntrl.XmodemMode) {
		Xmodem_SPI();return;
	}

	do{
		result = ReadUartNonBlock(&bt,1);
		if(result) {
			UART_SendByte(bt);
			if(bt == '\r'){
				//alt_putstr("Code!\n\r");
				Uart_Cntrl.buf[Uart_Cntrl.idx++] = 0;
				cmd_flag = 1;
			} else
				Uart_Cntrl.buf[Uart_Cntrl.idx++] = bt;
			if(Uart_Cntrl.idx >= UART_BUF_SIZE) Uart_Cntrl.idx = 0;
		}
	}while(result);
	if(!cmd_flag) return;
	Uart_Cntrl.idx = 0;
	if(!strlen(Uart_Cntrl.buf)){ UART_putstr("\n\r"); return;};
	if(!strcmp(Uart_Cntrl.buf,"help")){UART_putstr("ping!\n\r");return;};
	if(!strcmp(Uart_Cntrl.buf,"flash")){UART_putstr("Read flash id\n\r");ReadFlashID();return;};
	if(!strcmp(Uart_Cntrl.buf,"xmodem")){UART_putstr("Start XMODEM\n\r");Xmodem_Init();return;};
	if(!strcmp(Uart_Cntrl.buf,"bmc")){UART_putstr("Switch to BMC\n\r");Switch_BootSpi2BMC();return;};
	if(!strcmp(Uart_Cntrl.buf,"cpu")){UART_putstr("Switch to CP\n\r");Switch_BootSpi2CPU();return;};
	if(!strcmp(Uart_Cntrl.buf,"dump")){FlashDump();return;};
}
/*
int alt_avalon_spi_command(alt_u32 base, alt_u32 slave,
                           alt_u32 write_length, const alt_u8 * write_data,
                           alt_u32 read_length, alt_u8 * read_data,
                           alt_u32 flags);
*/

alt_u8 ByteToHEX(alt_u8 bt){
if(bt == 0 )return '0';
if(bt == 1 )return '1';
if(bt == 2 )return '2';
if(bt == 3 )return '3';
if(bt == 4 )return '4';
if(bt == 5 )return '5';
if(bt == 6 )return '6';
if(bt == 7 )return '7';
if(bt == 8 )return '8';
if(bt == 9 )return '9';
if(bt == 0xa )return 'A';
if(bt == 0xb )return 'B';
if(bt == 0xc )return 'C';
if(bt == 0xd )return 'D';
if(bt == 0xe )return 'E';
if(bt == 0xf )return 'F';
return 'X';
}
void FlashDump(){
	alt_u8 spi_command_string_tx[10];
	alt_u8 spi_command_string_rx[10];
	int return_code,i;
	alt_u8 buf[64];

	//Switch_BootSpi2BMC();

	spi_command_string_tx[0] = 0x0b;
	spi_command_string_tx[1] = 0x0;
	spi_command_string_tx[2] = 0x0;
	spi_command_string_tx[3] = 0x0;
	spi_command_string_tx[4] = 0x0;
	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			5, spi_command_string_tx,
			0, spi_command_string_rx,
			ALT_AVALON_SPI_COMMAND_MERGE);

	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			0, spi_command_string_tx,
			16, Uart_Cntrl.SPI_page,
			0);

	for (i=0;i<16;i++){
		UART_SendByte(ByteToHEX(Uart_Cntrl.SPI_page[i]>>4));
		UART_SendByte(ByteToHEX(Uart_Cntrl.SPI_page[i]&0x0f));
		UART_putstr("\n\r");
	}


}
void ReadFlashID(){
	alt_u8 spi_command_string_tx[10];
	alt_u8 spi_command_string_rx[10];
	int return_code,i;

	spi_command_string_tx[0] = 0x9E;
	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			1, spi_command_string_tx,
			16, Uart_Cntrl.SPI_rxbuf,
			0);
	/*
	alt_printf("Manufacturer ID - 0x%x\n\r",Uart_Cntrl.SPI_rxbuf[0]);
	alt_printf("Memory type - ");
	if(Uart_Cntrl.SPI_rxbuf[1] == 0xBA)
		alt_putstr("3V");
	else if(Uart_Cntrl.SPI_rxbuf[1] == 0xBB)
			alt_putstr("1V8");
	else alt_putstr("Unknown");
	alt_putstr("\n\rMemory size - ");
	switch(Uart_Cntrl.SPI_rxbuf[2]) {
		case 0x22: //2Gb
			alt_putstr("2Gb\n\r");
			break;
		case 0x21: //1Gb
			alt_putstr("1Gb\n\r");
			break;
		case 0x20: //512Mb
			alt_putstr("512Mb\n\r");
			break;
		case 0x19: //256Mb
			alt_putstr("256Mb\n\r");
			break;
		case 0x18:  // 128Mb
			alt_putstr("128Mb\n\r");
			break;
		case 0x17:	// 64M
			alt_putstr("64Mb\n\r");
			break;
		default:
			break;
	}
	*/
}
Switch_BootSpi2BMC();
void Xmodem_Init(){
	Uart_Cntrl.XmodemMode = 1;
	Uart_Cntrl.XmodemState = XMODEM_STATE_INIT;
	Uart_Cntrl.TryCounter = 100;
	Uart_Cntrl.TimerCnt = XMODEM_TIME_1SEC;
	Uart_Cntrl.SPI_address = 0;
	Switch_BootSpi2BMC();
	UART_putstr("C");
}

void Xmodem_SPI(){
	alt_u8 bt;
	int result,i;

	if(Uart_Cntrl.TimerCnt)Uart_Cntrl.TimerCnt--;

	switch(Uart_Cntrl.XmodemState) {
	case XMODEM_STATE_INIT:
		result = ReadUartNonBlock(&bt,1);
		if((result>0)) {
			if( bt == 0x01) {
				Uart_Cntrl.XmodemState = XMODEM_STATE_S0;
				Uart_Cntrl.X_idx = 0;

				Uart_Cntrl.SPI_page_idx = 0;
				Uart_Cntrl.bt_count = 128+4;
			}
		} else {
			if(!result && !Uart_Cntrl.TimerCnt) {
				Uart_Cntrl.TryCounter--;
				if(!Uart_Cntrl.TryCounter) {
					Uart_Cntrl.XmodemMode = 0;
					UART_putstr("Timout...\n\r");
				}
				else {
					Uart_Cntrl.TimerCnt = XMODEM_TIME_1SEC;
					UART_putstr("C");
				}
			}
		}
		break;
	case XMODEM_STATE_S0: // SOH code received
		//alt_u8 SPI_rxbuf[1024];
		//alt_u32 X_idx;
		//alt_u32 bt_count;
		result = ReadUartNonBlock(&Uart_Cntrl.SPI_rxbuf[Uart_Cntrl.X_idx],Uart_Cntrl.bt_count);
		if(result>0) {
			Uart_Cntrl.X_idx += result;
			Uart_Cntrl.bt_count -= result;
			if(!Uart_Cntrl.bt_count) {
				UART_SendByte(0x06); // ACK
				for(i=0;i<128;i++) {
					Uart_Cntrl.SPI_page[Uart_Cntrl.SPI_page_idx++] = Uart_Cntrl.SPI_rxbuf[i+2];
					//Uart_Cntrl.SPI_page[Uart_Cntrl.SPI_page_idx++] =Uart_Cntrl.SPI_page_idx;

				}
				if(Uart_Cntrl.SPI_page_idx >= 255)
					Flash_PageWrite();
				Uart_Cntrl.XmodemState = XMODEM_STATE_S1;
			}
		}
		break;
	case XMODEM_STATE_S1:
		result = ReadUartNonBlock(&bt,1);
		if(result>0){
			if((bt == 0x01)) {
					Uart_Cntrl.XmodemState = XMODEM_STATE_S0;
					Uart_Cntrl.X_idx = 0;
					Uart_Cntrl.bt_count = 128+4;
					} else if(bt == 0x04) {
						UART_SendByte(0x06); // ACK
					} else if(bt == 0x17) {
						UART_SendByte(0x06); // ACK
						Uart_Cntrl.XmodemState = XMODEM_STATE_INIT;
						Uart_Cntrl.XmodemMode = 0;
					}  else if(bt == 0x18) {
						UART_SendByte(0x06); // ACK
						UART_SendByte(0x06); // ACK
						Uart_Cntrl.XmodemState = XMODEM_STATE_INIT;
						Uart_Cntrl.XmodemMode = 0;
						UART_putstr("Canceled\n\r");
					}
			}

		break;
	case XMODEM_STATE_S2:
		break;
	case XMODEM_STATE_S3:
		break;
	}
}

void Flash_WriteEnable() {
	alt_u8 spi_command_string_tx[4];
	alt_u8 spi_command_string_rx[4];
	int return_code,i;

	spi_command_string_tx[0] = 0x06;
	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
		1, spi_command_string_tx,
		0, spi_command_string_rx,
		0);
}

alt_u8 Flash_ReadStatus() {
	alt_u8 spi_command_string_tx[4];
	alt_u8 spi_command_string_rx[4];
	int return_code,i;

	spi_command_string_tx[0] = 0x05;
	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
		1, spi_command_string_tx,
		1, spi_command_string_rx,
		0);
	return spi_command_string_rx[0];
}
void Flash_PageWrite() {
	alt_u8 spi_command_string_tx[10];
	alt_u8 spi_command_string_rx[10];
	int return_code,i;

	do{

	}while(Flash_ReadStatus()&1);

	if((Uart_Cntrl.SPI_address & 0xffff) == 0)
		Flash_SectorErase(Uart_Cntrl.SPI_address);

	Flash_WriteEnable();

	spi_command_string_tx[0] = 0x02;
	spi_command_string_tx[1] = (Uart_Cntrl.SPI_address>>16) & 0xff;
	spi_command_string_tx[2] = (Uart_Cntrl.SPI_address>>8)  & 0xff;
	spi_command_string_tx[3] = (Uart_Cntrl.SPI_address>>0)  & 0xff;

	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			4, spi_command_string_tx,
			0, spi_command_string_rx,
			ALT_AVALON_SPI_COMMAND_MERGE);

	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			Uart_Cntrl.SPI_page_idx, Uart_Cntrl.SPI_page,
			0, spi_command_string_rx,
			0);

	Uart_Cntrl.SPI_address += Uart_Cntrl.SPI_page_idx;

	Uart_Cntrl.SPI_page_idx = 0;

}
void Flash_SectorErase(alt_u32 addr) {
	alt_u8 spi_command_string_tx[10];
	alt_u8 spi_command_string_rx[10];
	int return_code,i;


	Flash_WriteEnable();

	spi_command_string_tx[0] = 0xD8;
	spi_command_string_tx[1] = (addr>>16) & 0xff;
	spi_command_string_tx[2] = (addr>>8)  & 0xff;
	spi_command_string_tx[3] = (addr>>0)  & 0xff;

	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			4, spi_command_string_tx,
			0, spi_command_string_rx,
			0);

	for(i=0;i<100;i++)asm("nop");

	do{

	}while(Flash_ReadStatus()&1);
}

void Test_SPI(){
	alt_u8 spi_command_string_tx[10];
	alt_u8 spi_command_string_rx[10];
	int return_code,i;

	spi_command_string_tx[0] = 0xD8;
	spi_command_string_tx[1] = 0x00;
	spi_command_string_tx[2] = 0x00;
	spi_command_string_tx[3] = 0x00;
	return_code = alt_avalon_spi_command(SPI_1_BASE,0,
			4, spi_command_string_tx,
			16, Uart_Cntrl.SPI_rxbuf,
			0);
	//for(i=0;i<16;i++)
		//alt_printf("0x%x\n\r",Uart_Cntrl.SPI_rxbuf[i]);
}

#define BAUDRATE 115200
void UART_Init(alt_u32 baundrate) {
	void* base = A_16550_UART_0_BASE;
	alt_u32 divisor;
	alt_u32 LCR;

	IOWR_ALTERA_16550_UART_FCR(base, ALTERA_16550_UART_FCR_FIFOE_MSK);
	IOWR_ALTERA_16550_UART_FCR(base, ALTERA_16550_UART_FCR_FIFOE_MSK |ALTERA_16550_UART_FCR_FIFOR_MSK |	ALTERA_16550_UART_FCR_XFIFOR_MSK);
	IOWR_ALTERA_16550_UART_FCR(base, 0x0);

	/* Clear any Error status */
	IORD_ALTERA_16550_UART_LSR(base);
	IORD_ALTERA_16550_UART_RBR(base);
	IORD_ALTERA_16550_UART_IIR(base);
	IORD_ALTERA_16550_UART_MSR(base);

	/* Configure default settings */
	IOWR_ALTERA_16550_UART_LCR(base, ((STOPB_1 << 2)| CS_8));

	LCR = IORD_ALTERA_16550_UART_LCR(base);
	IOWR_ALTERA_16550_UART_LCR(base, (LCR | ALTERA_16550_UART_LCR_DLAB_MSK));
	// Formula for calculating the divisor:
	//    baudrate = clock / (16 * divisor)
	// => baudrate * 16 * divisor = clock
	// => divisor = clock / (baudrate * 16)
	// => divisor = (clock / 16) / baudrate

	divisor = A_16550_UART_0_FREQ / (16*(baundrate));

	IOWR_ALTERA_16550_UART_DLL(base, (divisor & 0x00FF));
	IOWR_ALTERA_16550_UART_DLH(base, ((divisor >> 8)& 0x00FF));

	/* Clear LCR[7] after program Divisor */
	IOWR_ALTERA_16550_UART_LCR (base, (LCR & ~(ALTERA_16550_UART_LCR_DLAB_MSK)));

	IOWR_ALTERA_16550_UART_FCR(base, ALTERA_16550_UART_FCR_FIFOE_MSK);

	//IOWR(base, 0x104, 125); //watermark
	//IOWR(base, 0x100, 1);

}

void UART_SendByte(alt_u8 bt) {
	//while(! (IORD_ALTERA_16550_UART_LSR(A_16550_UART_0_BASE) & ALTERA_16550_UART_LSR_THRE_MSK));
	IOWR_ALTERA_16550_UART_THR(A_16550_UART_0_BASE,bt);
}

int ReadUartNonBlock(alt_u8 *buf,int size) {
	int cnt,lsr;
	cnt = 0;
	lsr = IORD_ALTERA_16550_UART_LSR(A_16550_UART_0_BASE);

	while((lsr&ALTERA_16550_UART_LSR_DR_MSK) && size) {
		buf[cnt++] = IORD_ALTERA_16550_UART_RBR(A_16550_UART_0_BASE);
		size--;
		lsr = IORD_ALTERA_16550_UART_LSR(A_16550_UART_0_BASE);
	}
	return cnt;
}
void UART_putstr(alt_u8 *str) {
	int len,i;
	len = strlen(str);
	for(i=0;i<len;i++)
		UART_SendByte(str[i]);
}
