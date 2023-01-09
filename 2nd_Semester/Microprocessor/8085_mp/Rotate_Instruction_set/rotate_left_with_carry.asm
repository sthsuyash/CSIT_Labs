; WAP to rotate left with carry the result of addition (AAH + EEH) three times

LXI B, AAEEH    ; Load B-C register pair with AAEEH
MOV A, C        ; Copy contents of C into accumulator
ADD B           ; Add contents of B[AAH] with accumulator
MVI D, 03H      ; Set D to 03 for counter to rotate 3 times
LOOP: RAL       ; Rotate contents of accumulator left with carry
DCR D           ; Decrease value of D by 1
JNZ LOOP        ; Jump to label 'LOOP' until the zero flag is set
HLT             ; Stop the program
