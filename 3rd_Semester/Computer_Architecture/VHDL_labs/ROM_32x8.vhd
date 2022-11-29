-- 32*8 ROM module 
-- ROM model has predefined content for read only purpose

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

-- Entity declaration for ROM 

ENTITY ROM IS
    PORT (
        Clock : IN STD_LOGIC;
        Reset : IN STD_LOGIC;
        Enable : IN STD_LOGIC;
        Read : IN STD_LOGIC;
        Address : IN STD_LOGIC_VECTOR(4 DOWNTO 0);
        Data_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
    );
END ROM;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE Behav OF ROM IS

    TYPE ROM_Array IS ARRAY (0 TO 31)
    OF STD_LOGIC_VECTOR(7 DOWNTO 0);

    CONSTANT Content : ROM_Array := (
        0 => "00000001", -- Suppose ROM has 
        1 => "00000010", -- prestored value
        2 => "00000011", -- like this table
        3 => "00000100", --
        4 => "00000101", --
        5 => "00000110", --
        6 => "00000111", --
        7 => "00001000", --
        8 => "00001001", --
        9 => "00001010", --
        10 => "00001011", --
        11 => "00001100", --
        12 => "00001101", --
        13 => "00001110", --
        14 => "00001111", --
        OTHERS => "11111111");

BEGIN
    PROCESS (Clock, Reset, Read, Address)
    BEGIN
        IF (Reset = '1') THEN
            Data_out <= "ZZZZZZZZ";
        ELSIF (Clock'event AND Clock = '1') THEN
            IF Enable = '1' THEN
                IF (Read = '1') THEN
                    Data_out <= Content(conv_integer(Address));
                ELSE
                    Data_out <= "ZZZZZZZZ";
                END IF;
            END IF;
        END IF;
    END PROCESS;
END Behav;