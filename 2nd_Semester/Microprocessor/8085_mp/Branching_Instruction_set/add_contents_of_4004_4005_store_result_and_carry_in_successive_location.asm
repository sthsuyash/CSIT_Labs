; WAP to add the content of 4004H and 4005H and store the result and carry in successive memory location

MVI C, 00H      ; Load C with 00H
LXI H, 4004H    ; Load HL pair with 4004H
MOV B, M        ; Copy from memory to B
INX H           ; Increase HL pair by 1
MOV A, M        ; Copy from memory to accumulator
ADD B           ; Add content of B with accumulator
INX H           ; Increase value of HL pair by 1
XCHG            ; Swap HL and DL contents
INC 4212H       ; Jump on carry to 4212H
STAX D          ; Copy accumulator into memory pointed by D 
INX D           ; Increase DE pair by 1
INR C           ; Increase value of C by 1
MOV A, C        ; Copy contents of C into accumulator
STAX D          ; Copy contents of accumulator into memory pointed by D
HLT             ; Stop the program
