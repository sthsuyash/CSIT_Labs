; WAP to rotate left the databyte A1H two times

MVI A, A1H  ; Load accumulator with A1H(data)
RLC         ; Rotate content of accumulator left by 1 bit
RLC         ; Rotate content of accumulator left by 1 bit
HLT         ; Stop the program
