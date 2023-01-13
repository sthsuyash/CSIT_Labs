; WAP to copy block of memory to another memory location

LXI D, 0006H    ; Load 0006H into D-E register pair
LXI H, 0000H    ; Load 0000H into H-L register pair
MOV B, M        ; Copy contents of memory into register B
LOOP: INX H     ; Increase value of HL pair by 1
MOV A, M        ; Copy contents of memory into accumulator
STAX D          ; Store contents of A into address designated by DE pair
INX D           ; Increase value of D-E pair by 1
DCR B           ; Decrease value of B by 1
JNZ LOOP        ; Jump to label 'LOOP' if zero flag is not set
HLT             ; Stop the program
