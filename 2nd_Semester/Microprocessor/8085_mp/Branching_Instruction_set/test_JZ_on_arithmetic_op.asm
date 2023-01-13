; WAP to test the Jump on Zero (JZ=1) condition on arithmetic operation

LXI B, 6969H    ; Load B-C with 6969H
MOV A, C        ; Copy contents of C to accumulator
SUB B           ; Subtract from B from accumulator
JZ 4204H        ; Jump on zero to 4204H
ADD B           ; Add B to accumulator
HLT             ; Stop the program
