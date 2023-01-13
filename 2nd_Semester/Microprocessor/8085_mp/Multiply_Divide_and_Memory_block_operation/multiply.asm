; WAP to multiply two numbers from memory

LXI H, 0000H    ; Load H-L register pair with 0000H
MOV B, M        ; Copy contents of memory into register B
INX H           ; Increaes value of register pair HL by 1
MOV C, M        ; Copy contents of memory to C register 
MVI A, 00H      ; Set accumulator with 00H
MVI D, 00H      ; Set D register with 00H 
LOOP: ADD B     ; Add contents of B register with accumulator
JNC HERE        ; If no carry, jump to label 'HERE'
INR D           ; If carry, increase D by 1
HERE: DCR C     ; Decrease value of C register by 1
JNZ LOOP        ; If zero flag is not set, jump to label 'LOOP'
STA 0003H       ; Store value of accumulator into [0003]
MOV A, D        ; Copy contents of D register into accumulator
STA 0002H       ; Store value of accumulator into 0002H
HLT             ; Stop the program
