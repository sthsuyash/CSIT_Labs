-- VHDL code for 32x8 RAM

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;

-- Entity declaration

ENTITY RAM_32X8 IS
    PORT (
        address : IN STD_LOGIC_VECTOR(4 DOWNTO 0);
        data_in : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        write_in : IN STD_LOGIC;
        clock : IN STD_LOGIC;
        data_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
    );
END RAM_32X8;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE Behav OF RAM_32X8 IS
    TYPE ram_array IS ARRAY (0 TO 31) OF STD_LOGIC_VECTOR (7 DOWNTO 0);
    SIGNAL ram_data : ram_array := (
        b"10000000", b"01001101", x"77", x"67",
        x"99", x"25", x"00", x"1A",
        x"00", x"00", x"00", x"00",
        x"00", x"00", x"00", x"00",
        x"00", x"0F", x"00", x"00",
        x"00", x"00", b"00111100", x"00",
        x"00", x"00", x"00", x"00",
        x"00", x"00", x"00", x"1F"
    );
BEGIN
    PROCESS (clock)
    BEGIN
        IF (rising_edge(clock)) THEN
            IF (write_in = '1') THEN
                ram_data(to_integer(unsigned(address))) <= data_in;
            END IF;
        END IF;
    END PROCESS;

    data_out <= ram_data(to_integer(unsigned(address)));
END Behav;

-- FOR Output :
-- FOR read
-- Address : 11111
-- Data IN : 10101010
-- Write : 1
-- Clock : 1
-- Run Output will be 00011111
-- FOR write
-- Address 11111
-- Data IN : 10101010
-- Write : 1
-- Clock : 0

-- Output will be : 10101010