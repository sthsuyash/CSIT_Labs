; WAP to create a continuous loop using unconditional jump instruction

LXI B, 1234H    ; Load 1234H into B-C register pair
MOV A, C        ; Copy C to accumulator
ADD B           ; Add B to accumulator
SUB B           ; Subtract content of B from accumulator
JMP 4204H       ; Jump to 4203H
HLT             ; Stop the program
