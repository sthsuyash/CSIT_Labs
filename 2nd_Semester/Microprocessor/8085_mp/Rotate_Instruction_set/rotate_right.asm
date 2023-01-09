; WAP to rotate right the databyte F1H three times

MVI A, F1H  ; Load accumulator with F1H(data)
RRC         ; Rotate content of accumulator right by 1 bit
RRC         ; Rotate content of accumulator right by 1 bit
RRC         ; Rotate content of accumulator right by 1 bit
HLT         ; Stop the program
