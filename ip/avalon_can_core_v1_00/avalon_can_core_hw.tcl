package require -exact qsys 14.0

source "../pearl_link_pkg/avalon_bus/pearl_link_pkg.tcl"

#------------------------------------------------------------------------------
# Module
#------------------------------------------------------------------------------
set_module_property NAME                  avalon_can_sja1000
set_module_property VERSION               1.0
set_module_property DISPLAY_NAME          "Avalon CAN Controller SJA1000"
set_module_property GROUP                 "Interface Protocols/Serial"
set_module_property AUTHOR                "Maksim Mikheev"
set_module_property EDITABLE              false
set_module_property HIDE_FROM_SOPC        true
set_module_property COMPOSITION_CALLBACK  composition_callback


#-------------------------------------------------------------------------
# CALLBACK
#-------------------------------------------------------------------------
proc composition_callback {} {
	# ---------------------------------------------------------------------
	# -- Module
	# ---------------------------------------------------------------------
	add_instance "module_inst" can_sja1000 1.0

	# ---------------------------------------------------------------------
	# -- Clocks and resets
	# ---------------------------------------------------------------------
	add_instance "reset_bridge" altera_reset_bridge
	set_instance_parameter_value "reset_bridge" SYNCHRONOUS_EDGES "none"
	
	add_interface "reset" reset end
	set_interface_property "reset" export_of "reset_bridge.in_reset"

	# clock bus
	add_clock_bridge "clk_bus"
	add_connection "clk_bus_bridge.out_clk"     "module_inst.clk_bus"
	
	add_reset_bridge "reset_bus"  "clk_bus"	
	add_connection "reset_bus_bridge.out_reset" "module_inst.reset_bus"
	
	# clock CAN
	add_clock_bridge "clk_can"
	add_connection "clk_can_bridge.out_clk"     "module_inst.clk_can"
	
	# ---------------------------------------------------------------------
	# -- CSR
	# ---------------------------------------------------------------------
	add_plite_slave_v2                  \
		"bus_csr" "csr"                 \
		"clk_bus_bridge.out_clk"        \
		"reset_bus_bridge.out_reset"
		
	add_connection "bus_csr.pearl_lite" "module_inst.pearl_lite" 
	set_instance_parameter_value "bus_csr" C_ADDRESS_WIDTH  [get_instance_port_property "module_inst" i_plite_address width]
	
	# ---------------------------------------------------------------------
	# -- CSR
	# ---------------------------------------------------------------------
	add_interface "can" conduit end
	set_interface_property "can" export_of "module_inst.can"
	
	add_interface "o_irq" interrupt sender
	set_interface_property "o_irq" export_of "module_inst.o_irq"
	
}