; Write an 8085 ALP to find the sum of squares of the first n numbers

LXI H, 0000H        ; Load HL pair with 0000H
MOV A, M            ; Copy data from memory to accumulator
MOB B, A            ; Copy data from accumulator to B register 
INR A               ; Increase value of A by 1
MOV C, A            ; Copy accumulator into C register
CALL MUL            ; Subroutine call to multiply
MOV D, A            ; Copy content of accumulator to D register
MOV A, M            ; Copy content of memory to accumulator
ADD A               ; Add contents of accumulator with accumulator
INR A               ; Increase value of accumulator by 1
MOV B, A            ; Copy accumulator value to B register
MOV C, D            ; Copy value of D register to C register
CALL MUL            ; Subroutine call to Multiply
MVI E, 06H          ; Set E to 06H
MVI C, 00H          ; Set C to 00H
DIV: SUB E          ; Subtract contents of E from accumulator 
INR C               ; Increase value of C by 1
CMP E               ; Compare contents of E with accumulator
JNC DIV             ; Jump to 'DIV' until carry flag is set 
INX H               ; Increase value of HL pair by 1
MOV M, C            ; Copy contents of C register to memory
HLT                 ; Stop the program 
MUL: MVI A, 00H     ; Set A to 00H
LOOP: ADD B         ; Add content of B register with accumulator 
DCR C               ; Decrement value of C register by 1
JNZ LOOP            ; Jump to 'LOOP' until B becomes 0
RET                 ; Return from subroutine
