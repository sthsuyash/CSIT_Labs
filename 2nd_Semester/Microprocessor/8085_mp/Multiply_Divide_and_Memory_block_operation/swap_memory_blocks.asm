; WAP to swap memory blocks

LXI H, 0000H    ; Load 0000H into register pair HL 
MOV B, M        ; Copy contents of memory into register B
LXI D, 0006H    ; Load 0006H into DE register
LOOP: INX H     ; Increase value of HL pair by 1
LDAX D          ; Copy contents designated by DE pair into accumulator
MOV C, M        ; Copy contents of memory into C register
MOV M, A        ; Copy accumulator into memory
MOV A, C        ; Copy contents of C register into accumulator
STAX D          ; Copy contents of accumulator into memory pointed by DE pair
INX D           ; Increase value of DE pair by 1
DCR B           ; Decrease value of B by 1
JNZ LOOP        ; Jump to label 'LOOP' if zero flag is not set
HLT             ; Stop the program
