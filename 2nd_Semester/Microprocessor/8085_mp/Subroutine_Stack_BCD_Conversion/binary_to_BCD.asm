; WAP to convert binary to BCD

LXI H, 0000H    ; Load HL pair with 0000H
MVI D, 00H      ; Load D register with 00H
MVI A, 00H      ; Load accumulator with 00H
MOV C, M        ; Copy contents of memory to C register
LOOP: ADI 01H   ; Add 01H into accumulator immediately
DAA             ; Adjust for BCD count
JNC SKIP        ; Jump to 'SKIP' if no carry
INR D           ; Increase value of D by 1
SKIP: DCR C     ; Decrease value of C by 1
JNZ LOOP        ; Jump to LOOP until C becomes 0
MOV L, A        ; Copy contents of accumulator to L register
MOV H, D        ; Copy contents of D register to H register
SHLD 0001H      ; Store contents of H and L register in respective positions
HLT             ; Stop the program
