; WAP to load two data stored in memory location 8000H and 8001H directly to HL register.
; Add them.
; If carry exists, rotate right with carry the accumulator result three times otherwise terminate.

LHLD 8000H  ; Load data of [8000] into L and [8001] into H 
MOV A, H    ; Copy content of H into accumulator
ADD L       ; Add content of L with accumulator
JNC SKIP    ; Check for carry, if there is no carry jump to label 'SKIP' else continue program
MVI C, 03H  ; If carry exists, load C with 03H for counter for rotation
LOOP: RAR   ; Rotate contents of accumulator right with carry
DCR C       ; Decrease value of C by 1 (decrease counter)
JNZ LOOP    ; Jump to loop until zero flag is set
SKIP: HLT   ; Stop the program
