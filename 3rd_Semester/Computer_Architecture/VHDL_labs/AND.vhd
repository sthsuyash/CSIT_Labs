-- VHDL code for AND gate

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- entity declaration

ENTITY and_gate IS
    PORT (
        input_1 : IN STD_LOGIC;
        input_2 : IN STD_LOGIC;
        and_result : OUT STD_LOGIC);
END and_gate;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE rtl OF and_gate IS
BEGIN
    and_result <= input_1 AND input_2;
END rtl;