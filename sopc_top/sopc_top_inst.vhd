	component sopc_top is
		port (
			altpll_0_areset_export    : in  std_logic                     := 'X';             -- export
			altpll_0_inclk0_clk       : in  std_logic                     := 'X';             -- clk
			altpll_0_locked_export    : out std_logic;                                        -- export
			bmc_spi_MISO              : in  std_logic                     := 'X';             -- MISO
			bmc_spi_MOSI              : out std_logic;                                        -- MOSI
			bmc_spi_SCLK              : out std_logic;                                        -- SCLK
			bmc_spi_SS_n              : out std_logic;                                        -- SS_n
			i2c_0_sda_in              : in  std_logic                     := 'X';             -- sda_in
			i2c_0_scl_in              : in  std_logic                     := 'X';             -- scl_in
			i2c_0_sda_oe              : out std_logic;                                        -- sda_oe
			i2c_0_scl_oe              : out std_logic;                                        -- scl_oe
			i2cslave_conduit_data_in  : in  std_logic                     := 'X';             -- conduit_data_in
			i2cslave_conduit_clk_in   : in  std_logic                     := 'X';             -- conduit_clk_in
			i2cslave_conduit_data_oe  : out std_logic;                                        -- conduit_data_oe
			i2cslave_conduit_clk_oe   : out std_logic;                                        -- conduit_clk_oe
			id32k_clk                 : out std_logic;                                        -- clk
			pio_in_export             : in  std_logic_vector(31 downto 0) := (others => 'X'); -- export
			pio_out_export            : out std_logic_vector(31 downto 0);                    -- export
			reset_bridge_0_in_reset_n : in  std_logic                     := 'X';             -- reset_n
			spi_0_MISO                : in  std_logic                     := 'X';             -- MISO
			spi_0_MOSI                : out std_logic;                                        -- MOSI
			spi_0_SCLK                : out std_logic;                                        -- SCLK
			spi_0_SS_n                : out std_logic;                                        -- SS_n
			uart_0_sin                : in  std_logic                     := 'X';             -- sin
			uart_0_sout               : out std_logic;                                        -- sout
			uart_0_sout_oe            : out std_logic                                         -- sout_oe
		);
	end component sopc_top;

	u0 : component sopc_top
		port map (
			altpll_0_areset_export    => CONNECTED_TO_altpll_0_areset_export,    --   altpll_0_areset.export
			altpll_0_inclk0_clk       => CONNECTED_TO_altpll_0_inclk0_clk,       --   altpll_0_inclk0.clk
			altpll_0_locked_export    => CONNECTED_TO_altpll_0_locked_export,    --   altpll_0_locked.export
			bmc_spi_MISO              => CONNECTED_TO_bmc_spi_MISO,              --           bmc_spi.MISO
			bmc_spi_MOSI              => CONNECTED_TO_bmc_spi_MOSI,              --                  .MOSI
			bmc_spi_SCLK              => CONNECTED_TO_bmc_spi_SCLK,              --                  .SCLK
			bmc_spi_SS_n              => CONNECTED_TO_bmc_spi_SS_n,              --                  .SS_n
			i2c_0_sda_in              => CONNECTED_TO_i2c_0_sda_in,              --             i2c_0.sda_in
			i2c_0_scl_in              => CONNECTED_TO_i2c_0_scl_in,              --                  .scl_in
			i2c_0_sda_oe              => CONNECTED_TO_i2c_0_sda_oe,              --                  .sda_oe
			i2c_0_scl_oe              => CONNECTED_TO_i2c_0_scl_oe,              --                  .scl_oe
			i2cslave_conduit_data_in  => CONNECTED_TO_i2cslave_conduit_data_in,  --          i2cslave.conduit_data_in
			i2cslave_conduit_clk_in   => CONNECTED_TO_i2cslave_conduit_clk_in,   --                  .conduit_clk_in
			i2cslave_conduit_data_oe  => CONNECTED_TO_i2cslave_conduit_data_oe,  --                  .conduit_data_oe
			i2cslave_conduit_clk_oe   => CONNECTED_TO_i2cslave_conduit_clk_oe,   --                  .conduit_clk_oe
			id32k_clk                 => CONNECTED_TO_id32k_clk,                 --             id32k.clk
			pio_in_export             => CONNECTED_TO_pio_in_export,             --            pio_in.export
			pio_out_export            => CONNECTED_TO_pio_out_export,            --           pio_out.export
			reset_bridge_0_in_reset_n => CONNECTED_TO_reset_bridge_0_in_reset_n, -- reset_bridge_0_in.reset_n
			spi_0_MISO                => CONNECTED_TO_spi_0_MISO,                --             spi_0.MISO
			spi_0_MOSI                => CONNECTED_TO_spi_0_MOSI,                --                  .MOSI
			spi_0_SCLK                => CONNECTED_TO_spi_0_SCLK,                --                  .SCLK
			spi_0_SS_n                => CONNECTED_TO_spi_0_SS_n,                --                  .SS_n
			uart_0_sin                => CONNECTED_TO_uart_0_sin,                --            uart_0.sin
			uart_0_sout               => CONNECTED_TO_uart_0_sout,               --                  .sout
			uart_0_sout_oe            => CONNECTED_TO_uart_0_sout_oe             --                  .sout_oe
		);

