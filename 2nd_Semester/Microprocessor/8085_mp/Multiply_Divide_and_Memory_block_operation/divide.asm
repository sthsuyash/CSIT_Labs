; WAP to divide two numbers from memory

LXI H, 0000H    ; Load 0000H in HL register pair
MOV A, M        ; Copy contents of memory into accumulator
INX H           ; Increase value of HL pair by 1
MOV B, M        ; Copy contents of memory to B register (divisor)
MVI C, 00H      ; Load 00H into C register (Quotient)
LOOP: SUB B     ; Subtract content of B register from accumulator
INR C           ; Increase value of C register by 1
CMP B           ; Compare value of accumulator and B register
JNC LOOP        ; if no carry flag is set, carry flag not set, ie. A > B , then jump to label 'LOOP'
STA 0003H       ; Store contents of accumulator into [0003] (remainder)
MOV A, C        ; Contents of C register copied to accumulator
STA 0004H       ; Store contents of accumulator into [0004] (Quotient)
HLT             ; Stop the program
