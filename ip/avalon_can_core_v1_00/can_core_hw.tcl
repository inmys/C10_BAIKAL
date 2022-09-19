package require -exact qsys 14.0

source "../utility_pkg/altera/utility_pkg.tcl"

#---------------------------------------------------------------------
# Module
#---------------------------------------------------------------------
set_module_property NAME                    can_sja1000
set_module_property VERSION                 1.0
set_module_property AUTHOR                  "Maksim Mikheev"
set_module_property EDITABLE                false
set_module_property HIDE_FROM_SOPC          true
set_module_property INTERNAL                true 

#---------------------------------------------------------------------
# File sets
#---------------------------------------------------------------------
add_fileset          synth_fileset QUARTUS_SYNTH ""
set_fileset_property synth_fileset TOP_LEVEL can_top

foreach fname_path [glob -directory "src_hdl" *.v] {
	set fname [file split $fname_path]
	set fname [lindex $fname [expr [llength $fname] - 1]]
	add_fileset_file $fname VERILOG PATH $fname_path
}

#---------------------------------------------------------------------
# Clock & Reset connection points
#---------------------------------------------------------------------
#         <interface> <port>
add_clock "clk_bus"   i_plite_clk
add_clock "clk_can"   clk_i

#         <interface>   <port>      <clock>
add_reset "reset_bus"   i_plite_rst "clk_bus"

#---------------------------------------------------------------------
# CSR
#---------------------------------------------------------------------
add_interface "pearl_lite" conduit end
#                  <interface>   <port>           <type>        <dir>  <width>
add_interface_port "pearl_lite"  i_plite_address  plite_address Input  8
add_interface_port "pearl_lite"  o_plite_rddata   plite_rddata  Output 32
add_interface_port "pearl_lite"  i_plite_rdreq    plite_rdreq   Input  1
add_interface_port "pearl_lite"  o_plite_rdresp   plite_rdresp  Output 1
add_interface_port "pearl_lite"  i_plite_wrdata   plite_wrdata  Input  32
add_interface_port "pearl_lite"  i_plite_wrreq    plite_wrreq   Input  1
add_interface_port "pearl_lite"  o_plite_wrresp   plite_wrresp  Output 1

#---------------------------------------------------------------------
# CAN
#---------------------------------------------------------------------
add_interface "can" conduit end
#                  <interface> <port>     <type> <dir>  <width>
add_interface_port "can"       tx_o       tx     Output 1
add_interface_port "can"       rx_i       rx     Input  1
add_interface_port "can"       bus_off_on bus_en Output 1

add_interface "o_irq" interrupt sender
set_interface_property "o_irq" associatedClock "clk_bus"
set_interface_property "o_irq" associatedReset "reset_bus"

#                  <interface> <port>     <type> <dir>  <width>
add_interface_port "o_irq"     irq_on     irq_n  Output 1
