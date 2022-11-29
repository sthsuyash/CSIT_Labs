-- VHDL code for Parallel IN Parallel OUT

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY pipo IS
    PORT (
        clk : IN STD_LOGIC;
        D : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        Q : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END pipo;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE arch OF pipo IS
BEGIN
    PROCESS (clk)
    BEGIN
        IF (CLK'event AND CLK = '1') THEN
            Q <= D;
        END IF;
    END PROCESS;
END arch;

-- D - flipflop
LIBRARY IEEE;
USE IEEE.Std_logic_1164.ALL;

ENTITY RisingEdge_DFlipFlop IS
    PORT (
        Q : OUT STD_LOGIC;
        Clk : IN STD_LOGIC;
        D : IN STD_LOGIC
    );
END RisingEdge_DFlipFlop;
ARCHITECTURE Behavioral OF RisingEdge_DFlipFlop IS
BEGIN
    PROCESS (Clk)
    BEGIN
        IF (rising_edge(Clk)) THEN
            Q <= D;
        END IF;
    END PROCESS;
END Behavioral;