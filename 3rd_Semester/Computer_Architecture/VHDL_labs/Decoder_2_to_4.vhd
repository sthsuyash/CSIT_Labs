-- VHDL code for Decoder 2:4

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration

ENTITY decoder IS
    PORT (
        a : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        b : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END decoder;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE bhv OF decoder IS
BEGIN
    PROCESS (a)
    BEGIN
        CASE a IS
            WHEN "00" => b <= "0001";
            WHEN "01" => b <= "0010";
            WHEN "10" => b <= "0100";
            WHEN "11" => b <= "1000";
        END CASE;
    END PROCESS;
END bhv;