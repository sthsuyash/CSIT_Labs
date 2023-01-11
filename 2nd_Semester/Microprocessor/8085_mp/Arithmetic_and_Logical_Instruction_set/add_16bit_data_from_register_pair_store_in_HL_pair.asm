; WAP to add 16-bit data from register pair B and D and store result at HL pair

LXI B, 4A00H    ; Load B-L pair with 4A00 
LXI D, 0F90H    ; Load D-E pair with 0F90
XCHG            ; Swap the contents of DE with HL 
DAD             ; Add contents of BC with HL
HLT             ; Stop the program
