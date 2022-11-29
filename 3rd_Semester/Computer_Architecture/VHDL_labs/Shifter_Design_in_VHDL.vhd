-- VHDL code for Shifter Design in VHDL

-- The input/ output interface of the shifter is shown in the figure in README. 
-- The shifter instruction set is as follows:
-- - SHIFT_Ctrl = "1000": SHIFTOUT <= Rotate SHIFTINPUT >>8
-- - SHIFT_Ctrl = "1001": SHIFTOUT <= Rotate SHIFTINPUT >>4
-- - SHIFT_Ctrl = "1010": SHIFTOUT <= Shift Left Logical SHIFTINPUT << 8

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration

ENTITY shifter IS
    PORT (
        SHIFTINPUT : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
        SHIFT_Ctrl : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        SHIFTOUT : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
    );
END shifter;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE Behavioral OF shifter IS

BEGIN
    PROCESS (SHIFTINPUT, SHIFT_Ctrl)
    BEGIN
        CASE(SHIFT_Ctrl) IS
            WHEN "1000" => SHIFTOUT <= SHIFTINPUT(7 DOWNTO 0) & SHIFTINPUT(15 DOWNTO 8);
            WHEN "1001" => SHIFTOUT <= SHIFTINPUT(3 DOWNTO 0) & SHIFTINPUT(15 DOWNTO 4);
            WHEN "1010" => SHIFTOUT <= SHIFTINPUT(7 DOWNTO 0) & "00000000";
            WHEN OTHERS => SHIFTOUT <= "00000000";
        END CASE;
    END PROCESS;

END Behavioral;