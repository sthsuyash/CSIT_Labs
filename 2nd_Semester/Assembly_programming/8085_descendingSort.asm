; Descending Sort

START: LXI H, 0000H     ; load 0000H into H-L pair.
MVI D, 00H              ; load 00H into D register.
MOV C, M                ; copy contents of memory into C register.
DCR C                   ; decrease value of C register by 1.
INX H                   ; increase value of H-L pair by 1.
CHECK: MOV A, M         ; compare memory with A(accumulator).
INX H                   ; increase value of H-L pair by 1.
CMP M                   ; compare memory with accumulator.
JNC NEXT                ; if carry flag is not set, jump to label 'NEXT'.
MOV B, M                ; copy contents of memory to B.
MOV M, A                ; copy contents of accumulator to memory.
DCX H                   ; decrease value of H-L pair by 1.
MOV M, B                ; copy contents of B register to memory.
INX H                   ; increase value of H-L pair by 1.
MVI D, O1H              ; load 01H into D register.
NEXT: DCR C             ; decrease value of C register by 1.
JNZ CHECK               ; jump to label 'CHECK' if zero flag is not set.
MOV A, D                ; copy contents of D register to accumulator.
RRC                     ; rotate accumulator right by 1 bit.
JC START                ; jump to label 'START' if carry flag is set.
HLT                     ; stop the program.