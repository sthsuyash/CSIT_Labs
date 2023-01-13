; WAP in 8085 microprocessor to set the D6, D1 and D0 bits of 8 bits data A8H and store the result in memory location 1010H.

MVI A, 0A8H ; Load A with 0A8H
ORI         ; OR 43H with A[SET] 
STA 1010H   ; Store contents of into [1010]
HLT         ; Stop the program
