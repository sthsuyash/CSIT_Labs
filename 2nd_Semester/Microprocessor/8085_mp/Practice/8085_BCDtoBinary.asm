; convert BCD to Binary

LDA 0000H       ; load accumulator with contents of [0000H].
MOV B, A        ; copy contents of accumulator to B register.
ANI OFH         ; mask upper nibble.
MOV C, A        ; copy contents of accumulator to C register.
MOV A, B        ; copy contents of B register to accumulator.
ANI FOH         ; mask lower nibble.
JZ SKIP         ; jump to label 'SKIP' if zero flag is set.
RRC             ; rotate accumulator right by 1 bit.
RRC             ; rotate accumulator right by 1 bit.
RRC             ; rotate accumulator right by 1 bit.
RRC             ; rotate accumulator right by 1 bit.
MOV D, A        ; copy contents of accumulator into D register.
MVI A, 00H      ; load 00H into accumulator.
MVI E, 0AH      ; load 0AH into E register.
LOOP: ADD D     ; add contents of accumulator with D register.
DCR E           ; decrease value of E register by 1.
JNZ LOOP        ; jump to label 'LOOP' if zero flag is not set.
SKIP: ADD C     ; add accumulator with contents of C register.
STA 0002H       ; store contents of accumulator in [0002H] memory location.
HLT             ; stop the program.
