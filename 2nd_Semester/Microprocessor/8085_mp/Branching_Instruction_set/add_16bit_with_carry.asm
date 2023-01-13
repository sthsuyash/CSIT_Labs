; WAP for addition of two 16 bit numbers with carry

MVI C, 00H      ; Load C with 00H 
LXI H, FFFFH    ; Load HL pair with FFFFH
LXI D, FFFFH    ; Load DL pair with FFFFH
DAD D           ; Add contents of DE with HL pair 
JNC 420DH       ; Jump on no carry to 420DH
INR C           ; Increase value of C by 1
HLT             ; Stop the program 
