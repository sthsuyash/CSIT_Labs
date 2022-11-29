-- VHDL code for NOT gate

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY not_gate IS
    PORT (
        input_1 : IN STD_LOGIC;
        not_result : OUT STD_LOGIC
    );
END not_gate;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE rtl OF not_gate IS
BEGIN
    not_result <= NOT input_1;
END rtl;