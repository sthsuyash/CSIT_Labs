; Write an 8085 ALP to convert BCD to binary

LDA 0000H       ; Load contents of [0000] into accumulator
MOV B, A        ; Copy contents of accumulator into B register
ANI OFH         ; Mask upper nibble
MOV C, A        ; Copy contents of accumulator to C register
MOV A, B        ; Copy contents of B register into accumulator
ANI FOH         ; Mask lower nibble 
JZ SKIP         ; Jump to 'SKIP' if A=0
RRC             ; Rotate contents of accumulator right 1 time
RRC 
RRC
RRC 
MOV D, A        ; Copy contents of accumulator to D register 
MVI A, 00H      ; Set A with 00H
MVI E, 0AH      ; Set E with 0AH
LOOP: ADD D     ; Add contents of D with accumulator
DCR E           ; Decrement value of E by 1
JNZ LOOP        ; Jump to 'LOOP' until E is 0
SKIP: ADD C     ; Add contents of C with accumulator
STA 0002H       ; Store contents of A in [0002]
HLT             ; Stop the program 
