-- VHDL code for OR gate

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY or_gate IS
    PORT (
        input_1 : IN STD_LOGIC;
        input_2 : IN STD_LOGIC;
        or_result : OUT STD_LOGIC
    );
END or_gate;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE rtl OF or_gate IS

BEGIN
    or_result <= input_1 OR input_2;
END rtl;