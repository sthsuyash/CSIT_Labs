-- VHDL code for Parity Generator

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration

ENTITY paritygen IS
  PORT (
    a : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
    even : OUT STD_LOGIC;
    odd : OUT STD_LOGIC);
END paritygen;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE paritygen_arch OF paritygen IS
  SIGNAL i : STD_LOGIC;
BEGIN
  i <= a(0) XOR a(1) XOR a(2);
  even <= i;
  odd <= NOT i;
END paritygen_arch;