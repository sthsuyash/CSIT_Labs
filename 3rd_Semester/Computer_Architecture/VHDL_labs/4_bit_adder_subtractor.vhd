-- VHDL code for 4 bit adder-subtractor

-- Header file declaration

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.ALL;

-- Entity declaration

ENTITY addsub IS
    PORT (
        E : IN STD_LOGIC;
        a : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        s : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
        cf : OUT STD_LOGIC;
        ovf : OUT STD_LOGIC
    );
END addsub;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE struct OF addsub IS
    SIGNAL c : STD_LOGIC_VECTOR(4 DOWNTO 0);
    SIGNAL bx : STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
    bx <= b XOR E & E & E & E;
    c(0) <= E;
    s <= a XOR bx XOR c(3 DOWNTO 0);
    c(4 DOWNTO 1) <= (a AND bx) OR (c(3 DOWNTO 0) AND (a XOR bx));
    cf <= c(4);
    ovf <= c(3) XOR c(4);
END struct;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration

ENTITY addsub IS
    PORT (
        OP : IN STD_LOGIC;
        A, B : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        R : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
        Cout, OVERFLOW : OUT STD_LOGIC);
END addsub;

-- Dataflow Modelling Style
-- Architecture declaration

ARCHITECTURE struct OF addsub IS
    COMPONENT Full_Adder IS
        PORT (
            X, Y, Cin : IN STD_LOGIC;
            sum, Cout : OUT STD_LOGIC);
    END COMPONENT;
    SIGNAL C1, C2, C3, C4 : STD_LOGIC;
    SIGNAL TMP : STD_LOGIC_VECTOR(3 DOWNTO 0);

BEGIN
    TMP <= B XOR OP & OP & OP;
    FA0 : Full_Adder PORT MAP(A(0), TMP(0), OP, R(0), C1);-- R0
    FA1 : Full_Adder PORT MAP(A(1), TMP(1), C1, R(1), C2);-- R1
    FA2 : Full_Adder PORT MAP(A(2), TMP(2), C2, R(2), C3);-- R2
    FA3 : Full_Adder PORT MAP(A(3), TMP(3), C3, R(3), C4);-- R3
    OVERFLOW <= C3 XOR C4;
    Cout <= C4;
END struct;