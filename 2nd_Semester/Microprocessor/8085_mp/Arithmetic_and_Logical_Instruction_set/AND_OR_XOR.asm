; Logical Instruction Set

; WAP to perform AND, OR and XOR operation between 51H and A2H.
; Store the AND result at 9000H, OR at 9001H and XOR at 9002H.

MVI C, 51H      ; Load C with 51H
MVI B, 0A2H     ; Load B with 0A2H 
MOV A, C        ; Copy contents of C to accumulator
ANA B           ; AND B with A
LXI D, 9000H    ; Load D-E pair with 9000H
STAX D          ; Store accumulator with memory pointed by D register
MOV A, C        ; Copy contents of C to accumulator
ORI 0A2H        ; OR A2H with accumulator
INX D           ; Increase D-E pair by 1
STAX D          ; Store accumulator at memory location pointed by D 
MOV A, C        ; Copy contents of C into accumulator
XRA B           ; XOR contents of B with A 
INX D           ; Increase value of D-E pair by 1
STAX D          ; Store content of A at location pointed by D
HLT             ; Stop the Program
