-- VHDL code for AND gate

-- Header file declaration

Half adder
library ieee;
use ieee.std_logic_1164.all;

-- Entity declaration

entity half_adder is
  port (
    input_1    : in  std_logic;
    input_2    : in  std_logic;
    sum        : out std_logic;
    carry      : out std_logic
    );
end half_adder;

-- Dataflow Modelling Style
-- Architecture declaration

architecture rtl of half_adder is
begin
  carry  <= input_1 and input_2;
  sum  <= input_1 xor input_2;
end rtl;
