; WAP to test the jump on even parity (JPE=1) condition on any logical operation

MVI A, 01H  ; Load 01H to accumulator
ANI 01H     ; AND 01H with accumulator
JPE 4209H   ; Jump on even parity to 4209H
ADI 68H     ; Add 68H with A
HLT         ; Stop the program 
