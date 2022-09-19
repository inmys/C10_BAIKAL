/*
 * defines.h
 *
 *  Created on: 22 июля 2020 г.
 *      Author: ikoml
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define POWER_STATE_INIT (0)
#define POWER_STATE_S0 	 (5)
#define POWER_STATE_S1 	 (10)
#define POWER_STATE_S2 	 (15)
#define POWER_STATE_S3 	 (20)
#define POWER_STATE_S4 	 (25)
#define POWER_STATE_ATX_FAIL (250)

#define GPIO_ENABLE_1V5  (1<<0)
#define GPIO_ENABLE_1V8  (1<<1)
#define GPIO_ENABLE_0V95 (1<<2)
#define GPIO_OE_SLOT_0	 (1<<3)
#define GPIO_OE_SLOT_1	 (1<<4)
#define GPIO_OE_SLOT_2	 (1<<5)
#define GPIO_OE_SLOT_3	 (1<<6)
#define GPIO_OE_BLK_REFCLK (1<<7)
#define GPIO_OE_PEX_REFCLK	(1<<8)
#define GPIO_SLOT_PERST		(1<<9)
#define GPIO_CLK_SSON		(1<<10)
#define GPIO_CLK_PWRGD		(1<<11)
#define GPIO_CLK_SDOE		(1<<12)

#define GPIO_BOOT_CFG_0 		 (1<<13)
#define GPIO_BOOT_CFG_1 		 (1<<14)
#define GPIO_CPU_RESET 		 (1<<15)
#define GPIO_PEX_PERST 		 (1<<16)
#define GPIO_PEX_NT_PERST 	 (1<<17)
#define GPIO_TEST_F14 		 (1<<18)
#define GPIO_ENA_CPU_BOOT_SPI (1<<19)
#define GPIO_TEST_SEL 		 (1<<20)
#define GPIO_SYS_RESET_N 	 (1<<21)
#define GPIO_ENA_BMC_SPI 	 (1<<22)

#define INPUT_GPIO_EXT_RESET (1<<10)
#define INPUT_GPIO_RST_PIN (1<<11)
#define INPUT_GPIO_PWR_PIN (1<<12)
#define INPUT_GPIO_SFP_RX_LOS (1<<13)
#define INPUT_GPIO_SFP_MODEDEF (1<<14)

#endif /* DEFINES_H_ */
