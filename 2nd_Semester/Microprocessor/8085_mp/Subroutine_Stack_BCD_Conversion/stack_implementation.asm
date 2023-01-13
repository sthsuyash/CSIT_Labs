; Write an 8085 ALP to demonstrate the stack implementation and add data directly

LXI B, 1111H
LXI SP, 0002H
PUSH B          ; 11H is stored at 0000H
                ; 11H is stored at 0001H
POP D           ; Load D with contents of [0000] and E with [0001]
MOV A, D
ADD E
STA 0002H
HLT             ; Stop the program
