; WAP to test the jump on negative (S=1) condition on arithmetic operation 

LXI B, 9669H    ; Load BC with 9669H
MOV A, B        ; Copy B to accumulator
SUB C           ; Subtract C from accumulator
JM 4209H        ; Jump on minus to 4209H
ADD A           ; Add accumulator with accumulator
HLT             ; Stop the program
