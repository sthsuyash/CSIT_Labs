; WAP to sort memory block in descending order

START: LXI H, 0000H     ; Load 0000H into HL pair
MVI D, 00H              ; Load 00H into D register
MOV C, M                ; Copy contents of memory into C
DCR C                   ; Decrease value of C by 1
INX H                   ; Increase value of HL pair by 1
CHECK: MOV A, M         ; Copy contents of memory into accumulator
INX H                   ; Increase value of HL pair by 1
CMP M                   ; Compare memory with accumulator
JNC NXT                 ; If carry flag is not set, ie. A>M, jump to label 'NXT'
MOV B, M
MOV M, A 
DCX H 
MOV M, B 
INX H
MVI D, 01H
NXT: DCR C              ; Decrease value of C by 1
JNZ CHECK               ; Jump to label 'CHECK' if zero flag is not set
MOV A, D                ; Copy contents of D register into accumulator
RRC                     ; Rotate contents of accumulator right by 1 bit
JC START                ; Jump to label 'START' if carry is set
HLT                     ; Stop the program
