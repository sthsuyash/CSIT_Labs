; WAP to Subtract 16-bit data of register pair D from register pair B and store the result at H-L pair

LXI B, 1133H    ; Load B-C with 1133H
LXI D, 2244H    ; Load D-E with 2244H
MOV A, C        ; Copy C to accumulator
SUB E           ; Subtract E from accumulator
MOV L, A        ; Copy contents of accumulator to L register
MOB A, B        ; Copy B to accumulator
SBB D           ; Subtract D with borrow from accumulator
MOV H, A        ; Copy accumulator to H
HLT             ; Stop the program
