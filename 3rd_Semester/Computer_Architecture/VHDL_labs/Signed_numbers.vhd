-- VHDL code for Signed Numbers

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

-- Entity declaration

ENTITY SignedTest1 IS
    PORT (
        in1, in2 : IN unsigned(3 DOWNTO 0);
        out1 : OUT unsigned(3 DOWNTO 0));
END SignedTest1;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE Behavioral OF SignedTest1 IS
BEGIN
    out1 <= in1 + in2;
END Behavioral;