MVI B, 42H  ; Load 42H into B
MVI C, 69H  ; Load 69H into C
MOV A, B    ; Copy content of B into A
MOB B, C    ; Copy content of C into B
MOV C, A    ; Copy content of A into C
HLT         ; Stop the program
