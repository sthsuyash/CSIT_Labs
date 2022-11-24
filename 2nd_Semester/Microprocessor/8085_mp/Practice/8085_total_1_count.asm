; count the number of ones in the contents of register B and store the result at memory location 3050. 

MVI B, 75H      ; load immediate 75H to B register.
MVI C, 08H	    ; load immediate 75H to C register.
MVI D 00H	    ; load immediate 00H to D register.
MOV A, B    	; copy contents of B register to accumulator.
ZERO: RRC       ; Rotate accumulator right without carry.
JNC JUM         ; Jump to label 'JUM' if carry flag is not set.
INR D           ; increase value of D by 1.
JUM: DCR C  	; decrease value of C by 1.
JNZ ZERO        ; Jump to label 'ZERO' if zero flag is not set.
MOV A, D        ; copy contents of D register to accumulator.
STA 3050H       ; store data of accumulator to memory location 3050.
HLT             ; stop the program
