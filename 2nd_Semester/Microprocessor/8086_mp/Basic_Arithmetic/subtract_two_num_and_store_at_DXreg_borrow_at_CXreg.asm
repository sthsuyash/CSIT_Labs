; WAP in 8086 to subtract two numbers F1H from 11H. Store the result at DL register and borrow at CL register

TITLE SUBTRACTION OF 8 BIT numbers
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
        MOV AH, 11H         ; Store 11H at AH register
        MOV AL, F1H         ; Store F1H at AL register
        MOV CL, 00H         ; Store 00H at CL register for borrow
        SUB AH, AL          ; Subtract contents of AL from AH
        JNC SKIP            ; Jump to 'SKIP' of no borrow
        INC CL              ; Increase CL by 1 if carry
        SKIP: MOV DL, AH    ; Copy contents fo AH(result) to DL
    MAIN ENDP               ; End main procedure
END MAIN                    ; End main program
