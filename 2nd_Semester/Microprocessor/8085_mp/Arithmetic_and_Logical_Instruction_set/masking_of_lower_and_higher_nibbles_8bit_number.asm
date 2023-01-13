; WAP in 8085 microprocessor showing masking of lower and higher nibbles of 8-bit number. 
; Store the original number in 7007H, masked lower nibble in 7008H and masked upper nibble in 7009H.

LXI D, 7007H    ; Load D-E with 7007H
MVI A, 56H      ; Load A with 56H
STAX D          ; Store A to memory location pointed by D
ANI 0F9H        ; AND 0F9H with A
INX D           ; Increase D-E by 1
STAX D          ; Store A to memory location D
MVI A, 56H      ; Load A with 56H
ANI 0AFH        ; AND 0AFH with A
INX D           ; Increase D-E pair by 1
STAX D          ; Store A into memory location pointed by D
HLT             ; Stop the program
