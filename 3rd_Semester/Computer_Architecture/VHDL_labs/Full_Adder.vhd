-- VHDL code for Full Adder

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY full_adder IS
    PORT (
        input_1 : IN STD_LOGIC;
        input_2 : IN STD_LOGIC;
        input_3 : IN STD_LOGIC;
        sum : OUT STD_LOGIC;
        carry : OUT STD_LOGIC
    );
END full_adder;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE rtl OF full_adder IS
BEGIN
    carry <= (input_1 AND input_2) OR (input_2 AND input_3) OR (input_3 AND input_1);
    sum <= ((input_1 XOR input_2) XOR input_3);
END rtl;