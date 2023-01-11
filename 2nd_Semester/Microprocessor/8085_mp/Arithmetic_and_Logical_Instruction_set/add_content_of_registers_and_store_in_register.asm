; WAP to add the content of register B and C and store the result at register D

MVI B, 12H  ; Load B with 12H
MVI C, ABH  ; Load C with ABH
MOV A, B    ; Copy contents of B to A
ADD C       ; Add C with A
MOV D, A    ; Copy A to D
HLT         ; Stop the program
