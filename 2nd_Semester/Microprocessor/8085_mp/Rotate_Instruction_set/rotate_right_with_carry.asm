; WAP to rotate right with carry the result of subtraction (DEH-FAH) two times

LXI B, DEFAH    ; Load B-C register pair with DEFAH
MVI D, 02H      ; Load 02H into D for counter for rotation
MOV A, B        ; Copy contents of B[DEH] into accumulator
SUB C           ; Subtract contents of C[FAH] from accumulator [DEH]
LOOP: RAR       ; Rotate contents of accumulator right with carry by 1 bit
DCR D           ; Decrease value of D by 1
JNZ LOOP        ; Jump to label 'LOOP' until zero flag is set
HLT             ; Stop the program
