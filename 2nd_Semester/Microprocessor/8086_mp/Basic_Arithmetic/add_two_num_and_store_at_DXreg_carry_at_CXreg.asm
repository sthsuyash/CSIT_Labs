; WAP in 8086 to add two numbers 1111H and F1F1H. Store the result at DX register and carry at CX register

TITLE ADDITION OF 16 BIT NUMBERS
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
            MOV AX, 1111H   ; Store 1111H at AX register pair
            MOV BX, F1F1H   ; Store F1F1H at BX register pair
            MOV CX, 0000H   ; Store 0000H at CX register pair
                            ; pair for carry
            ADD AX, BX      ; Add contents of BX to AX
            JNC SKIP        ; Jump to 'SKIP' if no carry
            INC CX          ; Increase value of CX by 1 if carry

    SKIP:   MOV DX, AX      ; Copy contents of AX(result)
            MAIN ENDP       ; End main procedure
    END MAIN                ; End program
