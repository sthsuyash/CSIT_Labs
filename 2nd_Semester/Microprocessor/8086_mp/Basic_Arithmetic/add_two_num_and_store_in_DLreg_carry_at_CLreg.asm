; WAP in 8086 to add two numbers 11H and F1H. Store the result at DL register and carry at CL register.

TITLE ADDITION OF NUMBERS
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
            MOV AL, 11H     ; Store 11H at AL register
            MOV AH, F1H     ; Store F1H at AH register
            MOV CX, 0000H   ; Store 0000H at CX register
                            ; pair for carry
            MOV DX, 0000H   ; Store 0000H at DX register
            ADD AL, AH      ; Add AL and AH and store in Al
            JNC SKIP        ; If no carry, jump to 'SKIP'
            INC CL          ; If carry, increment CL by 1
    SKIP:   MOV DL, AL    ; Copy contents of AL(result) to DL register

            MAIN ENDP       ; End main program
    END MAIN            ; End program
