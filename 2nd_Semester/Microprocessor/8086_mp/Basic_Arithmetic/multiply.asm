; WAP in 8086 to multiply
; a) 5 and 3
; b) AAH and 12H
; c) ABCDH and 1ABCH

TITLE MULTIPLY 
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
        MOV BH, 05H     ; Store 05H at BH register
        MOV AL, 03H     ; Store 03H at AL register
        MOV BH          ; Multiply BH and AL
        MOV BH, AAH     ; Store AAH at BH register
        MOV AL, 12H     ; Store 12H at AL register
        MUL BH          ; Multiply BH and AL
        MOV CX, 0000H   ; Store 0000H at CX register
        MOV BX, ABCDH   ; Store ABCDH at BX register
        MOV AX, 1ABCH   ; Store 1ABCH at AX register
        MUL BX          ; Multiply AX and BX
        JNC SKIP        ; Jump to 'SKIP' on no carry
        INC CX          ; Increase CX by 1 if carry
    SKIP: MAIN ENDP     ; End procedure
END MAIN                ; End program
