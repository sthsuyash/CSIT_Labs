-- VHDL code for Comparator

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY Comparator IS
    GENERIC (n : NATURAL := 2);
    PORT (
        A : IN STD_LOGIC_VECTOR(n - 1 DOWNTO 0);
        B : IN STD_LOGIC_VECTOR(n - 1 DOWNTO 0);
        less : OUT STD_LOGIC;
        equal : OUT STD_LOGIC;
        greater : OUT STD_LOGIC
    );
END Comparator;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE behv OF Comparator IS
BEGIN
    PROCESS (A, B)
    BEGIN
        IF (A < B) THEN
            less <= '1';
            equal <= '0';
            greater <= '0';
        ELSIF (A = B) THEN
            less <= '0';
            equal <= '1';
            greater <= '0';
        ELSE
            less <= '0';
            equal <= '0';
            greater <= '1';
        END IF;
    END PROCESS;
END behv;