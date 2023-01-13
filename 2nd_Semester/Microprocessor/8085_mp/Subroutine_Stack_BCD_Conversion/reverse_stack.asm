; Write an 8085 ALP to demonstrate the use of stack to reverse the number stored in a memory block and store in the same memory block

LXI B, 1122H    ; Load 1122H in B-C register pair 
LXI SP, 0002H   ; Initialize stack with 0002H
PUSH B          
POP D          
MOV H, D 
MOV D, E 
PUSH D 
HLT             ; Stop the program 
