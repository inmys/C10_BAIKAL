module C10_BAIKAL(
input wire clk,

//----------SFP PINS---------
input 	wire SFP_MODEDEF,
input 	wire SFP_TX_FAULT,
input 	wire SFP_RX_LOS,
input 	wire SFP_RS_0,
input 	wire SFP_RS_1,
output 	wire SFP_TXDIS,
output	wire SFP_PWR_ENA,
input		wire SFP_PWR_FLT,


//----------SFP PINS---------
/*
output	wire	SPI_CLK,
output	wire	SPI_MOSI,
input 	wire	SPI_MISO,
output	wire	SPI_CS_0,
output	wire	SPI_CS_1,
*/

//----------PMIC CONTROL-----
output	wire  DISABLE_1V5,
output	wire  DISABLE_1V8,
output	wire  DISABLE_0V95,
input 	wire	PMIC_PGOOD,
input 	wire	PEX_PGOOD,
//----------ATX PWR-----
input 	wire	ATX_PGOOD,
//output	wire	ATX_PWRON,

//----------Clock control----
inout 	wire	CLK_SCL,
inout 	wire	CLK_SDA,
output 	wire	CLK_SSON,
output 	wire	CLK_PWRGD,
output	wire	CLK_SDOE,
//---PCIE slot pins--------------------------------------
input 	wire	SLOT_PRSNT_0,
input 	wire	SLOT_PRSNT_1,
input 	wire	SLOT_PRSNT_2,
input 	wire	SLOT_PRSNT_3,
output	wire	OE_SLOT_0,
output	wire	OE_SLOT_1,
output	wire	OE_SLOT_2,
output	wire	OE_SLOT_3,
output	wire	OE_BLK_REFCLK,
output	wire	OE_PEX_REFCLK,
output	wire	SLOT_PERST,

output	wire	UART_TXD,
input		wire	UART_RXD,

//------------------------------------
// BANK 8
inout		wire	BOOT_CFG_0,
inout		wire	BOOT_CFG_1,
inout		wire	CPU_RESET,
input		wire	TAHO_IN_1_1V8,
inout		wire	PEX_FATAL,
inout		wire	PEX_PERST,
inout		wire	PEX_NT_PERST,

inout		wire	XAUI_PDTRXAN,
inout		wire	XAUI_LS_OK_IN,
inout		wire	XAUI_LS_OK_OUT,
inout		wire	XAUI_LOSA,
input		wire	TAHO_IN_2_1V8,
//-----------------------------------
// BANK 7
inout 	wire	HP_PWRFLT_A,
inout 	wire	PEX_HPC_INT,
inout 	wire	HP_PRSNT_A,
inout 	wire	HP_BUTTON_A,
inout 	wire	HP_PWREN_A,
inout 	wire	HP_MRL_A,
inout 	wire	CPU_INT,
inout 	wire	HP_PWR_GOOD,
inout 	wire	HP_PWR_LED,
inout 	wire	HP_CLKEN,
inout 	wire	HP_PERSTA,
inout 	wire	HP_ATNLED,

//------------------------------------
// BANK 3 1V8
output	wire	TEST_F14,
output	wire	ENA_CPU_BOOT_SPI,
output	wire	TEST_SEL,
input		wire	EXT_CPURESET,
output	wire	FAN_1_PWM,

inout		wire	PM_I2C_SDA,
inout		wire	PM_I2C_SCL,

output	wire	SYS_RESET_N,
output	wire	FAN_2_PWM,
inout		wire	CPU_TXD,
inout		wire	CPU_RXD,
//------------------------
output	wire BMC_SPI_CLK,
output	wire BMC_SPI_CS,
inout		wire BMC_SPI_MOSI,
inout 	wire BMC_SPI_MISO,


//----------DIP_SW----
input 	wire  DIP_SW_1,
input 	wire  DIP_SW_2,
input 	wire  DIP_SW_3,
input 	wire  DIP_SW_4,

//----------GPIO Serial 2 Parralel----
// BANK 2
input 	wire  RST_SW,
input 	wire  PWR_BTN,
output	wire	GPIO_CS,
output	wire	GPIO_CLK,
output	wire	GPIO_MOSI,
input		wire	GPIO_MISO


);


wire	i2c_0_sda_in;
wire	i2c_0_scl_in;
wire	i2c_0_sda_oe;
wire	i2c_0_scl_oe;

assign CLK_SCL = i2c_0_scl_oe ? 1'b0 : 1'bz;
assign CLK_SDA = i2c_0_sda_oe ? 1'b0 : 1'bz;
assign i2c_0_scl_in = CLK_SCL;
assign i2c_0_sda_in = CLK_SDA;

assign XAUI_PDTRXAN = 1'b1;

reg [7:0] reset_rr = 8'h0;

always @(posedge clk) begin
	if(reset_rr[7] == 1'b0) begin
		reset_rr <= reset_rr + 1'b1;
		end
end

wire id32k_clk;
wire pll_0_locked;
wire [31:0] pio_in;
wire INT_SPI_BUF_ENA;

wire [31:0] pio_out;

assign pio_in[0] = ATX_PGOOD;
assign pio_in[1] = SLOT_PRSNT_0;
assign pio_in[2] = SLOT_PRSNT_1;
assign pio_in[3] = SLOT_PRSNT_2;
assign pio_in[4] = SLOT_PRSNT_3;

assign pio_in[10] = EXT_CPURESET;
assign pio_in[11] = RST_SW;
assign pio_in[12] = PWR_BTN;
assign pio_in[13] = SFP_RX_LOS;
assign pio_in[14] = SFP_MODEDEF;


assign DISABLE_1V5  = ~pio_out[0];
assign DISABLE_1V8  = ~pio_out[1]; 
assign DISABLE_0V95 = ~pio_out[2];

assign OE_SLOT_0 = ~pio_out[3];
assign OE_SLOT_1 = ~pio_out[4];
assign OE_SLOT_2 = ~pio_out[5];
assign OE_SLOT_3 = ~pio_out[6];
assign OE_BLK_REFCLK = ~pio_out[7];
assign OE_PEX_REFCLK = ~pio_out[8];
assign SLOT_PERST 	= pio_out[9];
assign CLK_SSON		= pio_out[10];
assign CLK_PWRGD		= pio_out[11];
assign CLK_SDOE		= pio_out[12];

//BANK 7

assign HP_PWRFLT_A 	= 1'bz;
assign PEX_HPC_INT 	= 1'bz;

//assign HP_PRSNT_A 	= 1'bz;
assign HP_BUTTON_A 	= 1'bz;

assign HP_MRL_A 		= (PMIC_PGOOD) ? 1'b0 : 1'bz;
assign HP_PRSNT_A 	= (PMIC_PGOOD) ? 1'b0 : 1'bz;
//assign CPU_INT 		= 1'bz;

// Output
assign HP_PWR_GOOD 	= 1'bz;
assign HP_PWR_LED 	= 1'bz;
assign HP_CLKEN	 	= 1'bz;
assign HP_PERSTA 		= 1'bz;
assign HP_PWREN_A 	= 1'bz;
assign HP_ATNLED 		= 1'bz;


assign BOOT_CFG_0		= (PMIC_PGOOD) ? pio_out[13] : 1'bz;
assign BOOT_CFG_1		= (PMIC_PGOOD) ? pio_out[14] : 1'bz;
assign CPU_RESET		= (PMIC_PGOOD) ? ~pio_out[15] : 1'bz;
assign PEX_PERST		= (PMIC_PGOOD) ? pio_out[16] : 1'bz;
//assign PEX_NT_PERST	= (PMIC_PGOOD) ? pio_out[17] : 1'bz;
assign PEX_NT_PERST	= (PMIC_PGOOD) ? 1'b1 : 1'bz;
assign TEST_F14 			= (PMIC_PGOOD) ? pio_out[18] : 1'b0;
//assign TEST_F14 			= ( DIP_SW_1 && PMIC_PGOOD) ? 1'b1 : 1'b0;

assign ENA_CPU_BOOT_SPI = (PMIC_PGOOD) ? pio_out[19] : 1'bz;
//assign TEST_SEL 			= (PMIC_PGOOD) ? id32k_clk : 1'bz;
assign TEST_SEL 			= ( DIP_SW_2 && PMIC_PGOOD) ? 1'b1 : 1'b0;

assign SYS_RESET_N		= (PMIC_PGOOD) ? pio_out[21] : 1'b0;
assign INT_SPI_BUF_ENA  = pio_out[22];

wire w_bmc_spi_MOSI;
wire w_bmc_spi_SCLK;
wire w_bmc_spi_SS_n;

assign BMC_SPI_MOSI  = (~INT_SPI_BUF_ENA) ? 1'bz : w_bmc_spi_MOSI;
assign BMC_SPI_CLK 	= (~INT_SPI_BUF_ENA) ? 1'bz : w_bmc_spi_SCLK;
assign BMC_SPI_CS 	= (~INT_SPI_BUF_ENA) ? 1'bz : w_bmc_spi_SS_n;

/*
output	wire	TEST_F14,
output	wire	ENA_CPU_BOOT_SPI,
output	wire	TEST_SEL,
input		wire	EXT_CPURESET,
output	wire	FAN_1_PWM,
inout		wire	PM_I2C_SDA,
inout		wire	PM_I2C_SCL,
output	wire	SYS_RESET_N,
output	wire	FAN_2_PWM,
inout		wire	CPU_TXD,
inout		wire	CPU_RXD,
*/

wire			spi_pins_dclk;
wire			spi_pins_ncs;
wire [3:0]  spi_pins_data;

/*
assign BMC_SPI_CLK = spi_pins_dclk;
assign BMC_SPI_CS = spi_pins_ncs;
assign BMC_SPI_MOSI = spi_pins_data[0];
assign BMC_SPI_MISO = spi_pins_data[1];
*/

assign SFP_PWR_ENA = SFP_MODEDEF ? 1'b1 : 1'b0;
assign SFP_TXDIS = 1'b0;

wire	i2cslave_conduit_data_in;
wire	i2cslave_conduit_clk_in;
wire	i2cslave_conduit_data_oe;
wire	i2cslave_conduit_clk_oe;

//assign	PM_I2C_SDA = i2cslave_conduit_data_oe ? 1'b0 : 1'bz;
//assign	PM_I2C_SCL = i2cslave_conduit_clk_oe  ? 1'b0 : 1'bz;
//assign 	i2cslave_conduit_data_in = PM_I2C_SDA;
//assign	i2cslave_conduit_clk_in  = PM_I2C_SCL;

wire i2c_int;
assign CPU_INT = (i2c_int) ? 1'b1 : 1'b0;

I2C_to_GPIO i2g_0 (
	.sda(PM_I2C_SDA),
	.sclk(PM_I2C_SCL),
	.rst_n(pll_0_locked & reset_rr[7]),
	.int(i2c_int),
	.GPIO_input({4'hf,2'b0,SFP_RX_LOS,SFP_MODEDEF}),
	.GPIO_output()
	);



sopc_top sopc_0(				
		.altpll_0_inclk0_clk(clk),
		.altpll_0_areset_export(~reset_rr[7]),
		.altpll_0_locked_export(pll_0_locked),
		.reset_bridge_0_in_reset_n(pll_0_locked & reset_rr[7]),
		
		.id32k_clk(id32k_clk),                 //             id32k.clk
		
		//-------------------------------------------------------------------
		// GPIO SPI
		.spi_0_MISO(GPIO_MISO),
		.spi_0_MOSI(GPIO_MOSI),
		.spi_0_SCLK(GPIO_CLK),
		.spi_0_SS_n(GPIO_CS),
		
		//.uart_0_rxd(UART_RXD),
		//.uart_0_txd(UART_TXD),
		.uart_0_sin(UART_RXD),
		.uart_0_sout(UART_TXD),
		.uart_0_sout_oe(),
		
		.i2cslave_conduit_data_in(),
		.i2cslave_conduit_clk_in(),
		.i2cslave_conduit_data_oe(),
		.i2cslave_conduit_clk_oe(),

		
/*		
		.i2cslave_conduit_data_in(i2cslave_conduit_data_in),
		.i2cslave_conduit_clk_in(i2cslave_conduit_clk_in),
		.i2cslave_conduit_data_oe(i2cslave_conduit_data_oe),
		.i2cslave_conduit_clk_oe(i2cslave_conduit_clk_oe),
*/
		
		//
		//.pio_i2c_export({32'bz}),
		
		.bmc_spi_MISO(BMC_SPI_MISO),
		.bmc_spi_MOSI(w_bmc_spi_MOSI),
		.bmc_spi_SCLK(w_bmc_spi_SCLK),
		.bmc_spi_SS_n(w_bmc_spi_SS_n),
		
		.i2c_0_sda_in(i2c_0_sda_in),
		.i2c_0_scl_in(i2c_0_scl_in),
		.i2c_0_sda_oe(i2c_0_sda_oe),
		.i2c_0_scl_oe(i2c_0_scl_oe),
		.pio_in_export(pio_in),
		.pio_out_export(pio_out)
		
	);


endmodule