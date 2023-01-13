; WAP to subtract the content of register C from register B and store the difference at register L and borrow at register H

LXI B, 0012H    ; Load register B with 00H and C with 12H
MVI D, 10H      ; Load D with 10H 
MOV A, D        ; Copt contents of D register to accumulator
SUB C           ; Subtract contents of C from A 
MOV L, A        ; Copy contents of accumulator to L register
JNC 4200H       ; Jump on no carry to 4200H
INR B           ; Increase value of B by 1
MOV H, B        ; Copy contents of B to H
HLT             ; Stop the program

