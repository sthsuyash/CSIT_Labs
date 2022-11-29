-- VHDL code for Gray Code to Binary  Converter

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration for Gray Code to Binary Converter

ENTITY gtob IS
    PORT (
        g : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        b : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END gtob;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE gtob_ar OF gtob IS
BEGIN
    b(3) <= g(3);
    b(2) <= g(3) XOR g(2);
    b(1) <= g(3) XOR g(2)XOR g(1);
    b(0) <= g(3) XOR g(2)XOR g(1)XOR g(0);
END gtob_ar;