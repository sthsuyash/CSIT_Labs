; WAP to sort memory block in ascending order 

START: LXI H, 0000H     ; Load 0000H into H-L pair
MVI D, 00H              ; Load 00H into D
MOV C, M                ; Copy contents of memory into C register
DCR D                   ; Decrease value of C by 1
INX H                   ; Increase value of HL pair by 1
CHECK: MOV A, M         ; Compare memory with accumulator
INX H                   ; Increase value of HL pair by 1
CMP M                   ; Compare memory with accumulator
JC NEXT                 ; Jump to label 'NEXT', if carry flag is set ,ie(A) < M
MOV B, M 
MOV M, A 
DCX H 
MOV M, B 
INX H 
MVI D, 01H 
NEXT: DCR C  
JNZ CHECK               ; Jump to label 'CHECK' if zero flag is not set
MOV A, D                ; Copy contents of D register into accumulator
RRC                     ; Rotate accumulator right by 1 bit
JC START                ; Jump to label 'START' if carry is set 
HLT                     ; Stop the program 
