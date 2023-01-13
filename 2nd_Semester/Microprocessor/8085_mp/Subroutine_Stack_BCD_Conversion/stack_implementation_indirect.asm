; Write an 8085 ALP to demonstrate the stack implementation and add data directly

LXI H, 0002H
LXI B, 1111H
SPHL            ; Initialize SP with 0002H
PUSH B          ; 11H is stored at 0000H
                ; 11H is stored at 0001H
LXI H, 0000H    ; Load HL pair with 0000H
MOV A, M
INX H
ADD M 
STA 0002H
HLT             ; Stop the program
