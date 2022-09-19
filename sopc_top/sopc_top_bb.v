
module sopc_top (
	altpll_0_areset_export,
	altpll_0_inclk0_clk,
	altpll_0_locked_export,
	bmc_spi_MISO,
	bmc_spi_MOSI,
	bmc_spi_SCLK,
	bmc_spi_SS_n,
	i2c_0_sda_in,
	i2c_0_scl_in,
	i2c_0_sda_oe,
	i2c_0_scl_oe,
	i2cslave_conduit_data_in,
	i2cslave_conduit_clk_in,
	i2cslave_conduit_data_oe,
	i2cslave_conduit_clk_oe,
	id32k_clk,
	pio_in_export,
	pio_out_export,
	reset_bridge_0_in_reset_n,
	spi_0_MISO,
	spi_0_MOSI,
	spi_0_SCLK,
	spi_0_SS_n,
	uart_0_sin,
	uart_0_sout,
	uart_0_sout_oe);	

	input		altpll_0_areset_export;
	input		altpll_0_inclk0_clk;
	output		altpll_0_locked_export;
	input		bmc_spi_MISO;
	output		bmc_spi_MOSI;
	output		bmc_spi_SCLK;
	output		bmc_spi_SS_n;
	input		i2c_0_sda_in;
	input		i2c_0_scl_in;
	output		i2c_0_sda_oe;
	output		i2c_0_scl_oe;
	input		i2cslave_conduit_data_in;
	input		i2cslave_conduit_clk_in;
	output		i2cslave_conduit_data_oe;
	output		i2cslave_conduit_clk_oe;
	output		id32k_clk;
	input	[31:0]	pio_in_export;
	output	[31:0]	pio_out_export;
	input		reset_bridge_0_in_reset_n;
	input		spi_0_MISO;
	output		spi_0_MOSI;
	output		spi_0_SCLK;
	output		spi_0_SS_n;
	input		uart_0_sin;
	output		uart_0_sout;
	output		uart_0_sout_oe;
endmodule
