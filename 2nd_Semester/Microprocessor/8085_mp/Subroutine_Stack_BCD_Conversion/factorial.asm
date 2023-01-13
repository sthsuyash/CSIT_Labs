; Write an 8085 ALP to find the factorial of a number using subroutine

LXI H, 0000H    ; Load 0000H into H-L pair
MOV B, M        ; Load data from memory to B register
MVI D, 01H      ; Set D register with 1
FACT: CALL MUL  ; Subroutine call for multiplication
DCR B           ; Decrease value of B register by 1
JNZ FACT        ; Jump to 'FACT' until B becomes 0
INX H           ; Increase value of H-L pair by 1
MOV M, D        ; Copy contents of D into memory    
HLT             ; Stop the program 
MUL: MOV E, B   ; Copy contents of B into E 
MVI A, 00H      ; Set 00H  into accumulator
LOOP: ADD D     ; Add contents of D with accumulator
DCR E           ; Decrease value of D by 1
JNZ LOOP        ; Jump to 'LOOP' until E becomes 0
MOV D, A        ; Copy contents of accumulator into D register
RET             ; Return from Subroutine
