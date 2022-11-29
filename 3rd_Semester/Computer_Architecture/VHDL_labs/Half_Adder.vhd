-- VHDL code for Half Adder

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY half_adder IS
    PORT (
        input_1 : IN STD_LOGIC;
        input_2 : IN STD_LOGIC;
        sum : OUT STD_LOGIC;
        carry : OUT STD_LOGIC
    );
END half_adder;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE rtl OF half_adder IS
BEGIN
    carry <= input_1 AND input_2;
    sum <= input_1 XOR input_2;
END rtl;