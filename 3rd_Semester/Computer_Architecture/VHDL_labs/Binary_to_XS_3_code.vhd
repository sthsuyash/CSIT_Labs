-- VHDL code for Binary TO Excess 3 code

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration

ENTITY Binary_to_Excess3 IS
    PORT (
        din : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END Binary_to_Excess3;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE Binary_to_excess3_arc OF Binary_to_Excess3 IS
BEGIN

    WITH din SELECT
        dout <= "0011" WHEN "0000",
        "0100" WHEN "0001",
        "0101" WHEN "0010",
        "0110" WHEN "0011",
        "0111" WHEN "0100",
        "1000" WHEN "0101",
        "1001" WHEN "0110",
        "1010" WHEN "0111",
        "1011" WHEN "1000",
        "1100" WHEN "1001",
        "ZZZZ" WHEN OTHERS;

END Binary_to_excess3_arc;