-- VHDL code for ROM

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- Entity declaration

ENTITY ROM IS
    PORT (
        address : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END ENTITY ROM;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE RTL OF ROM IS
    TYPE MEMORY_16_4 IS ARRAY (0 TO 15) OF STD_LOGIC_VECTOR(3 DOWNTO 0);
    CONSTANT ROM_16_4 : MEMORY_16_4 := (
        x"0",
        x"1",
        x"2",
        x"3",
        x"4",
        x"5",
        x"6",
        x"7",
        x"8",
        x"9",
        x"a",
        x"b",
        x"c",
        x"d",
        x"e",
        x"f"
    );
BEGIN
    main : PROCESS (address)
    BEGIN
        dout <= ROM_16_4(to_integer(unsigned(address)));
    END PROCESS main;

END ARCHITECTURE RTL;

-- For Output:
-- Address:0000
-- Output will be :0000

-- Address:1111
-- Output will be:1111