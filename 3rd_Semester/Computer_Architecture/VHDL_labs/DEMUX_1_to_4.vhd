-- VHDL code for 1:4 DEMUX

-- Header file declaration

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Entity declaration for the demultiplexer

ENTITY demux_1to4 IS
    PORT (
        F : IN STD_LOGIC;
        S0, S1 : IN STD_LOGIC;
        A, B, C, D : OUT STD_LOGIC
    );
END demux_1to4;

-- Dataflow Modelling Style
-- Architecture declaration for the demultiplexer

ARCHITECTURE bhv OF demux_1to4 IS
BEGIN
    PROCESS (F, S0, S1) IS
    BEGIN
        IF (S0 = '0' AND S1 = '0') THEN
            A <= F;
            B <= 0;
            C <= 0;
            D <= 0;
        ELSIF (S0 = '1' AND S1 = '0') THEN
            A <= 0;
            B <= F;
            C <= 0;
            D <= 0;
        ELSIF (S0 = '0' AND S1 = '1') THEN
            A <= 0;
            B <= 0;
            C <= F;
            D <= 0;
        ELSE
            A <= 0;
            B <= 0;
            C <= 0;
            D <= F;
        END IF;
    END PROCESS;
END bhv;