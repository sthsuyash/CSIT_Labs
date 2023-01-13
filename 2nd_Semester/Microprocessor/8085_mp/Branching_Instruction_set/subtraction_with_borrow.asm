; WAP for subtraction of two 16-bit numbers with borrow

LXI B, 1133H    ; Load B-C with 1133H
LXI D, 2244H    ; Load D-E with 2244H
MOV A, C        ; Copy C to accumulator
SUB E           ; Subtract E from A 
MOV C, A        ; Copy accumulator to C register
MVI H, 00H      ; Load H with 00H 
MOV A, B        ; Copy B into accumulator
SBB D           ; Subtract D with borrow from accumulator
MOV B, A        ; Copy accumulator into B register
JNC 4212H       ; Jump if no carry to 4212H
INR H           ; Increase value of H by 1
HLT             ; Stop the program
