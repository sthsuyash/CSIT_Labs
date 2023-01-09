; WAP to convert the total no. of 1 in given bit number

MVI B, FFH      ; Load FFH into register B
MVI C, 08H      ; Load 08H into register C
MVI D, 00H      ; Load 00H into register D
MOV A, B        ; Copy content of register B into accumulator
HERE: RRC       ; Rotate contents of accumulator right without carry
JNC APPLE       ; Jump to label 'APPLE' if no carry flag is set.
INR D           ; If carry flag is set, increase value of D by 1
APPLE: DCR C    ; Decrease value of C by 1, total bits counted counter
JNZ HERE        ; Jump until zero flag is set to 'HERE'
MOV A, D        ; If zero flag is set, copy contents of D to A.
HLT             ; Stop the program
