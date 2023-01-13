; WAP to load 00H into register B and 10H into register C.
; Increment the content of register B.
; Decrement the content of register C.
; Store the incremented result at memory location 4000H
; and decremented value at memory location 4001H

LXI B, 0001H    ; Load B with 00H and C with 10H
INR B           ; Increase value of B by 1
DCR C           ; Decrease value of C by 1
MOV L, B        ; Copy B to L
MOV H, C        ; Copy C to H
SHLD 4000       ; Store L at [4000] and H at [4001]
HLT             ; Stop the program
