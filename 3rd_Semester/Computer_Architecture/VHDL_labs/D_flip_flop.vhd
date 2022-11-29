-- VHDL code for D-flip-flop

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY d_latch IS
    PORT (
        c, d : IN STD_LOGIC;
        q, nq : OUT STD_LOGIC);
END d_latch;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE arch OF d_latch IS
    SIGNAL qt, nqt : STD_LOGIC;
BEGIN
    qt <= (d NAND c) NAND nqt;
    nqt <= ((NOT d) NAND c) NAND qt;

    q <= qt;
    nq <= nqt;

END arch;

-- -- VHDL code for D - flipflop

-- -- Header file declaration

-- LIBRARY IEEE;
-- USE IEEE.Std_logic_1164.ALL;

-- -- Entity declaration

-- ENTITY RisingEdge_DFlipFlop IS
-- PORT (
-- Q : OUT STD_LOGIC;
-- Clk : IN STD_LOGIC;
-- D : IN STD_LOGIC
-- );
-- END RisingEdge_DFlipFlop;

-- -- Dataflow Modelling Style
-- -- Architecture declaration

-- ARCHITECTURE Behavioral OF RisingEdge_DFlipFlop IS
-- BEGIN
-- PROCESS (Clk)
-- BEGIN
-- IF (rising_edge(Clk)) THEN
-- Q <= D;
-- END IF;
-- END PROCESS;