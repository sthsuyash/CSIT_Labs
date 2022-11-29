-- VHDL code for Program TO implement Multiplier using VHDL

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

-- two 4-bit inputs and one 8-bit outputs
ENTITY multiplier IS
    PORT (
        num1, num2 : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        product : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END multiplier;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE behv OF multiplier IS

BEGIN
    PROCESS (num1, num2)

        VARIABLE num1_reg : STD_LOGIC_VECTOR(2 DOWNTO 0);
        VARIABLE product_reg : STD_LOGIC_VECTOR(5 DOWNTO 0);

    BEGIN

        num1_reg := '0' & num1;
        product_reg := "0000" & num2;

        -- use variables doing computation
        -- algorithm is to repeat shifting/adding
        FOR i IN 1 TO 3 LOOP
            IF product_reg(0) = '1' THEN
                product_reg(5 DOWNTO 3) := product_reg(5 DOWNTO 3)
                + num1_reg(2 DOWNTO 0);
            END IF;
            product_reg(5 DOWNTO 0) := '0' & product_reg(5 DOWNTO 1);
        END LOOP;

        -- assign the result of computation back to output signal
        product <= product_reg(3 DOWNTO 0);

    END PROCESS;

END behv;