; Add two 16 bit number in 8086 microprocessor

TITLE Addition of 16 bit numbers
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
        MOV AX, 1111H       ; store 1111H at AX register.
        MOV BX, F1F1H       ; store F1F1H at BX register.
        MOV CX, 0000H       ; store 0000H at CX register pair for carry.
        ADD AX, BX          ; add contents of BX with AX.
        JNC SKIP            ; jump to label 'SKIP' if carry flag is not set.
        INC CX              ; increase value of CX by 1 (if carry).
        SKIP: MOV DX, AX    ; copy contents of AX(result).
        MAIN ENDP           ; end main procedure.
    END MAIN                ; end program.