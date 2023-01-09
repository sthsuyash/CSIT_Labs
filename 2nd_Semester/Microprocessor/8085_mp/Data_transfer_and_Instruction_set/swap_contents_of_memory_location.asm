LDA 1010H   ; Copy contents of 1010H into accumulator
MOV B, A    ; Copy contents of accumulator into B register
LDA 4000H   ; Copy contents of 4000H into accumulator
STA 1010H   ; Store value of accumulator into memory location 1010H
MOV A, B    ; Copy contents of B register into accumulator
STA 4000H   ; Store value of accumulator into memory location 4000H
HLT         ; Stop the program
