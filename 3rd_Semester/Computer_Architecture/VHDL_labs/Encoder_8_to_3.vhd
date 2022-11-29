-- VHDL code for 8:3 encoder

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration

ENTITY encoder8_3 IS
    PORT (
        din : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(2 DOWNTO 0)
    );
END encoder8_3;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE encoder8_3_arc OF encoder8_3 IS
BEGIN
    dout <= "000" WHEN (din = "10000000") ELSE
        "001" WHEN (din = "01000000") ELSE
        "010" WHEN (din = "00100000") ELSE
        "011" WHEN (din = "00010000") ELSE
        "100" WHEN (din = "00001000") ELSE
        "101" WHEN (din = "00000100") ELSE
        "110" WHEN (din = "00000010") ELSE
        "111";
END encoder8_3_arc;