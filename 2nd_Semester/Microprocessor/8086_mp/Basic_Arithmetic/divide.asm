; WAP in 8086 to divide
; a) 5 by 3
; b) AAH by 12H

TITLE DIVIDE
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
        MOV AL, 05H     ; Store 05H at AL register
        MOV BL, 03H     ; Store 03H at Bl register
        DIV BL          ; Divide contents of AL by BL
        MOV AL, AAH     ; Store AAH at AL register
        MOV BL, 12H     ; Store 12H at BL register
        DIV BL          ; Divide contents of AL by BL
    MAIN ENDP           ; End main procedure
END MAIN                ; End main program
