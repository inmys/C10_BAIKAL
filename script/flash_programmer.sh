#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting Binary File: D:\555\bfk.rom to: "..\flash/bfk_generic_quad_spi_controller2_0_avl_mem.flash"
#
bin2flash --input="D:/555/bfk.rom" --output="../flash/bfk_generic_quad_spi_controller2_0_avl_mem.flash" --location=0x0 --verbose 

#
# Programming File: "..\flash/bfk_generic_quad_spi_controller2_0_avl_mem.flash" To Device: generic_quad_spi_controller2_0_avl_mem
#
nios2-flash-programmer "../flash/bfk_generic_quad_spi_controller2_0_avl_mem.flash" --base=0x20000000 --sidp=0x10000000 --id=0xDEADCAFE --timestamp=1595527177 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

