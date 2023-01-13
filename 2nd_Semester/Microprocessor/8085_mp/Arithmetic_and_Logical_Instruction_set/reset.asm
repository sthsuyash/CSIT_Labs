; WAP to RESET the D4, D3, D2 and D0 bits of 8-bit data 3DH and store the result in register B

MVI A, 30H  ; Load 30H to accumulator
ANI 0E2H    ; AND 0E2H with accumulator[RESET]
MOV B, A    ; Copy contents of accumulator into B register
HLT         ; Stop the program
