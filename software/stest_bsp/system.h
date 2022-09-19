/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'sopc_top'
 * SOPC Builder design path: ../../sopc_top.sopcinfo
 *
 * Generated: Mon Sep 05 11:07:29 UTC 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 512
#define ALT_CPU_INST_ADDR_WIDTH 0x11
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00010000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 512
#define NIOS2_INST_ADDR_WIDTH 0x11
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00010000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_16550_UART
#define __ALTERA_AVALON_I2C
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone 10 LP"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/null"
#define ALT_STDERR_BASE 0x0
#define ALT_STDERR_DEV null
#define ALT_STDERR_TYPE ""
#define ALT_STDIN "/dev/null"
#define ALT_STDIN_BASE 0x0
#define ALT_STDIN_DEV null
#define ALT_STDIN_TYPE ""
#define ALT_STDOUT "/dev/null"
#define ALT_STDOUT_BASE 0x0
#define ALT_STDOUT_DEV null
#define ALT_STDOUT_TYPE ""
#define ALT_SYSTEM_NAME "sopc_top"


/*
 * a_16550_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_a_16550_uart_0 altera_16550_uart
#define A_16550_UART_0_BASE 0x10000800
#define A_16550_UART_0_FIFO_DEPTH 256
#define A_16550_UART_0_FIFO_MODE 1
#define A_16550_UART_0_FIO_HWFC 1
#define A_16550_UART_0_FIO_SWFC 0
#define A_16550_UART_0_FREQ 100000000
#define A_16550_UART_0_IRQ 5
#define A_16550_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define A_16550_UART_0_NAME "/dev/a_16550_uart_0"
#define A_16550_UART_0_SPAN 512
#define A_16550_UART_0_TYPE "altera_16550_uart"


/*
 * altpll_0 configuration
 *
 */

#define ALTPLL_0_BASE 0x50
#define ALTPLL_0_IRQ -1
#define ALTPLL_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ALTPLL_0_NAME "/dev/altpll_0"
#define ALTPLL_0_SPAN 16
#define ALTPLL_0_TYPE "altpll"
#define ALT_MODULE_CLASS_altpll_0 altpll


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * i2c_0 configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_0 altera_avalon_i2c
#define I2C_0_BASE 0x10000080
#define I2C_0_FIFO_DEPTH 64
#define I2C_0_FREQ 100000000
#define I2C_0_IRQ 0
#define I2C_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define I2C_0_NAME "/dev/i2c_0"
#define I2C_0_SPAN 64
#define I2C_0_TYPE "altera_avalon_i2c"
#define I2C_0_USE_AV_ST 0


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x10000010
#define JTAG_UART_0_IRQ 1
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x10000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "sopc_top_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 16384
#define ONCHIP_MEMORY2_0_SPAN 16384
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * onchip_memory2_1 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_1 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_1_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_1_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_1_BASE 0x10000600
#define ONCHIP_MEMORY2_1_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_1_DUAL_PORT 1
#define ONCHIP_MEMORY2_1_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_1_INIT_CONTENTS_FILE "sopc_top_onchip_memory2_1"
#define ONCHIP_MEMORY2_1_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_1_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_1_IRQ -1
#define ONCHIP_MEMORY2_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_1_NAME "/dev/onchip_memory2_1"
#define ONCHIP_MEMORY2_1_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_1_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_1_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_1_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_1_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_1_SIZE_VALUE 256
#define ONCHIP_MEMORY2_1_SPAN 256
#define ONCHIP_MEMORY2_1_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_1_WRITABLE 1


/*
 * pio_in configuration
 *
 */

#define ALT_MODULE_CLASS_pio_in altera_avalon_pio
#define PIO_IN_BASE 0x10000040
#define PIO_IN_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_IN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_IN_CAPTURE 0
#define PIO_IN_DATA_WIDTH 32
#define PIO_IN_DO_TEST_BENCH_WIRING 0
#define PIO_IN_DRIVEN_SIM_VALUE 0
#define PIO_IN_EDGE_TYPE "NONE"
#define PIO_IN_FREQ 100000000
#define PIO_IN_HAS_IN 1
#define PIO_IN_HAS_OUT 0
#define PIO_IN_HAS_TRI 0
#define PIO_IN_IRQ -1
#define PIO_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_IN_IRQ_TYPE "NONE"
#define PIO_IN_NAME "/dev/pio_in"
#define PIO_IN_RESET_VALUE 0
#define PIO_IN_SPAN 16
#define PIO_IN_TYPE "altera_avalon_pio"


/*
 * pio_out configuration
 *
 */

#define ALT_MODULE_CLASS_pio_out altera_avalon_pio
#define PIO_OUT_BASE 0x10000020
#define PIO_OUT_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_OUT_BIT_MODIFYING_OUTPUT_REGISTER 1
#define PIO_OUT_CAPTURE 0
#define PIO_OUT_DATA_WIDTH 32
#define PIO_OUT_DO_TEST_BENCH_WIRING 0
#define PIO_OUT_DRIVEN_SIM_VALUE 0
#define PIO_OUT_EDGE_TYPE "NONE"
#define PIO_OUT_FREQ 100000000
#define PIO_OUT_HAS_IN 0
#define PIO_OUT_HAS_OUT 1
#define PIO_OUT_HAS_TRI 0
#define PIO_OUT_IRQ -1
#define PIO_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_OUT_IRQ_TYPE "NONE"
#define PIO_OUT_NAME "/dev/pio_out"
#define PIO_OUT_RESET_VALUE 0
#define PIO_OUT_SPAN 32
#define PIO_OUT_TYPE "altera_avalon_pio"


/*
 * spi_0 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_0 altera_avalon_spi
#define SPI_0_BASE 0x10000200
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 1
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 24
#define SPI_0_DATAWIDTH 32
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 1
#define SPI_0_IRQ 3
#define SPI_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NAME "/dev/spi_0"
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SPAN 32
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 5000000u
#define SPI_0_TARGETSSDELAY "0.0"
#define SPI_0_TYPE "altera_avalon_spi"


/*
 * spi_1 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_1 altera_avalon_spi
#define SPI_1_BASE 0x10000400
#define SPI_1_CLOCKMULT 1
#define SPI_1_CLOCKPHASE 0
#define SPI_1_CLOCKPOLARITY 0
#define SPI_1_CLOCKUNITS "Hz"
#define SPI_1_DATABITS 8
#define SPI_1_DATAWIDTH 16
#define SPI_1_DELAYMULT "1.0E-9"
#define SPI_1_DELAYUNITS "ns"
#define SPI_1_EXTRADELAY 0
#define SPI_1_INSERT_SYNC 0
#define SPI_1_IRQ 4
#define SPI_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_1_ISMASTER 1
#define SPI_1_LSBFIRST 0
#define SPI_1_NAME "/dev/spi_1"
#define SPI_1_NUMSLAVES 1
#define SPI_1_PREFIX "spi_"
#define SPI_1_SPAN 32
#define SPI_1_SYNC_REG_DEPTH 2
#define SPI_1_TARGETCLOCK 128000u
#define SPI_1_TARGETSSDELAY "0.0"
#define SPI_1_TYPE "altera_avalon_spi"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x10000000
#define SYSID_QSYS_0_ID -559035650
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1662376040
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x10000100
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 100000000
#define TIMER_0_IRQ 2
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 99999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
