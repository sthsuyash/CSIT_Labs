; WAP to subtract the content of memory location 5000H from the content of memory location 5001H and store the result in memory location 5002H

LXI H, 5000H    ; Load HL pair with 5000H
MOV B, M        ; Copy contents of memory to B register
INX H           ; Increase HL pair by 1
MOV A, M        ; Copy content of memory location to accumulator
SUB B           ; Subtract B from A 
STA 5002H       ; Copy content of accumulator to [5002]
HLT             ; Stop the program
