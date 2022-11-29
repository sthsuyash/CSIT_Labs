-- VHDL code for Binary TO Gray Code Converter

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY btog IS
    PORT (
        b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        g : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END btog;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE btog_ar OF btog IS
BEGIN
    g(3) <= b(3);
    g(2) <= b(3) XOR b(2);
    g(1) <= b(2)XOR b(1);
    g(0) <= b(1) XOR b(0);
END btog_ar;