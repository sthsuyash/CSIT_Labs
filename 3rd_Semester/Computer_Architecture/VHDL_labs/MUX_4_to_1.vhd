-- VHDL code for 4:1 MUX

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration

ENTITY mux_4to1 IS
    PORT (
        A, B, C, D : IN STD_LOGIC;
        S0, S1 : IN STD_LOGIC;
        Z : OUT STD_LOGIC
    );
END mux_4to1;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE bhv OF mux_4to1 IS
BEGIN
    PROCESS (A, B, C, D, S0, S1) IS
    BEGIN
        IF (S0 = '0' AND S1 = '0') THEN
            Z <= A;
        ELSIF (S0 = '1' AND S1 = '0') THEN
            Z <= B;
        ELSIF (S0 = '0' AND S1 = '1') THEN
            Z <= C;
        ELSE
            Z <= D;
        END IF;
    END PROCESS;
END bhv;