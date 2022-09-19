	sopc_top u0 (
		.altpll_0_areset_export    (<connected-to-altpll_0_areset_export>),    //   altpll_0_areset.export
		.altpll_0_inclk0_clk       (<connected-to-altpll_0_inclk0_clk>),       //   altpll_0_inclk0.clk
		.altpll_0_locked_export    (<connected-to-altpll_0_locked_export>),    //   altpll_0_locked.export
		.bmc_spi_MISO              (<connected-to-bmc_spi_MISO>),              //           bmc_spi.MISO
		.bmc_spi_MOSI              (<connected-to-bmc_spi_MOSI>),              //                  .MOSI
		.bmc_spi_SCLK              (<connected-to-bmc_spi_SCLK>),              //                  .SCLK
		.bmc_spi_SS_n              (<connected-to-bmc_spi_SS_n>),              //                  .SS_n
		.i2c_0_sda_in              (<connected-to-i2c_0_sda_in>),              //             i2c_0.sda_in
		.i2c_0_scl_in              (<connected-to-i2c_0_scl_in>),              //                  .scl_in
		.i2c_0_sda_oe              (<connected-to-i2c_0_sda_oe>),              //                  .sda_oe
		.i2c_0_scl_oe              (<connected-to-i2c_0_scl_oe>),              //                  .scl_oe
		.i2cslave_conduit_data_in  (<connected-to-i2cslave_conduit_data_in>),  //          i2cslave.conduit_data_in
		.i2cslave_conduit_clk_in   (<connected-to-i2cslave_conduit_clk_in>),   //                  .conduit_clk_in
		.i2cslave_conduit_data_oe  (<connected-to-i2cslave_conduit_data_oe>),  //                  .conduit_data_oe
		.i2cslave_conduit_clk_oe   (<connected-to-i2cslave_conduit_clk_oe>),   //                  .conduit_clk_oe
		.id32k_clk                 (<connected-to-id32k_clk>),                 //             id32k.clk
		.pio_in_export             (<connected-to-pio_in_export>),             //            pio_in.export
		.pio_out_export            (<connected-to-pio_out_export>),            //           pio_out.export
		.reset_bridge_0_in_reset_n (<connected-to-reset_bridge_0_in_reset_n>), // reset_bridge_0_in.reset_n
		.spi_0_MISO                (<connected-to-spi_0_MISO>),                //             spi_0.MISO
		.spi_0_MOSI                (<connected-to-spi_0_MOSI>),                //                  .MOSI
		.spi_0_SCLK                (<connected-to-spi_0_SCLK>),                //                  .SCLK
		.spi_0_SS_n                (<connected-to-spi_0_SS_n>),                //                  .SS_n
		.uart_0_sin                (<connected-to-uart_0_sin>),                //            uart_0.sin
		.uart_0_sout               (<connected-to-uart_0_sout>),               //                  .sout
		.uart_0_sout_oe            (<connected-to-uart_0_sout_oe>)             //                  .sout_oe
	);

