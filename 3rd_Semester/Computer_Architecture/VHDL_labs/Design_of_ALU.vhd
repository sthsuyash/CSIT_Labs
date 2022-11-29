-- Design of ALU
--  _______________________________________
-- | Selection Input | Operation Performed |
-- |  0  |  0  |  0  | A + B               |
-- |  0  |  0  |  1  | A - B               |
-- |  0  |  1  |  0  | A - 1               |
-- |  0  |  1  |  1  | A + 1               |  
-- |  1  |  0  |  0  | A and B             |
-- |  1  |  0  |  1  | A or B              |
-- |  1  |  1  |  0  | not A               |
-- |  1  |  1  |  1  | A xor B             |
--  ---------------------------------------

-- VHDL code for the 8-bit ALU

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE ieee.std_logic_unsigned.ALL;

-- Entity declaration

ENTITY alu_d IS
    PORT (
        inp_a : IN signed(3 DOWNTO 0);
        inp_b : IN signed(3 DOWNTO 0);
        sel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
        out_alu : OUT signed(3 DOWNTO 0)
    );
END alu_d;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE Behavioral OF alu_d IS
BEGIN
    PROCESS (inp_a, inp_b, sel)
    BEGIN
        CASE sel IS
            WHEN "000" =>
                out_alu <= inp_a + inp_b; --addition 
            WHEN "001" =>
                out_alu <= inp_a - inp_b; --subtraction 
            WHEN "010" =>
                out_alu <= inp_a - 1; --sub 1 
            WHEN "011" =>
                out_alu <= inp_a + 1; --add 1 
            WHEN "100" =>
                out_alu <= inp_a AND inp_b; --AND gate 
            WHEN "101" =>
                out_alu <= inp_a OR inp_b; --OR gate 
            WHEN "110" =>
                out_alu <= NOT inp_a; --NOT gate 
            WHEN "111" =>
                out_alu <= inp_a XOR inp_b; --XOR gate 
            WHEN OTHERS =>
                NULL;
        END CASE;
    END PROCESS;
END Behavioral;

-- Alternative ALU

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE ieee.std_logic_unsigned.ALL;

-- Entity declaration

ENTITY ALU IS
    PORT (
        selection_line : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
        a : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        ans : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END ALU;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE ALU_arc OF ALU IS
BEGIN
    PROCESS (selection_line, a, b) IS
    BEGIN
        IF (selection_line = "000") THEN
            ans <= a + b;
        ELSIF (selection_line = "001") THEN
            ans <= a - b;
        ELSIF (selection_line = "010") THEN
            ans <= a - 1;
        ELSIF (selection_line = "011") THEN
            ans <= a + 1;
        ELSIF (selection_line = "100") THEN
            ans <= a AND b;
        ELSIF (selection_line = "101") THEN
            ans <= a OR b;
        ELSIF (selection_line = "110") THEN
            ans <= NOT(a);
        ELSE
            ans <= a XOR b;
        END IF;
    END PROCESS;
END ALU_arc;

-- The process is the key structure in behavioral VHDL modeling. 
-- A process is the only means by which the executable functionality of a component is defined. 
-- In fact, for a model to be capable of being simulated, all components in the model must be defined using one or more processes. 
-- Statements within a process are executed sequentially (although care needs to be used in signal assignment statements since they do not take effect immediately; 
-- this was covered in the VHDL Basics module when the VHDL timing model was discussed). 
-- Variables are used as internal place holders which take on their assigned values immediately. 
-- All processes in a VHDL description are executed concurrently. 
-- That is, although statements within a process are evaluated and executed sequentially, all processes within the model begin executing concurrently.