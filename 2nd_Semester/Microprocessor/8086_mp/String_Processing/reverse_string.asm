; WAP in 8086 to display the string "Abcdefgh" in reverse.

TITLE REVERSE string
.MODEL SMALL
.STACK
.DATA
    orgstr db "Abcdefgh$"
    revstr db ?
    len dw 8

.CODE
    MAIN PROC
        ; Initialize data segment
        MOV AX, DATA
        MOV DS, AX
        LEA SI, orgstr          ; Load initial address of orgstr
        ADD SI, len             ; Add len to SI
        MOV DI, OFFSET REVSTR   ; Load initial address of revstr
        ACTREV: DEC SI          ; Decrease SI by 1
        MOV AL, [SI]            ; Copy contents of SI to AL
        MOV [DI], AL            ; Copy contents of AL to DI 
        INC DI                  ; Increase DI by 1
        LOOP ACTREV             ; LOOP to ACTREV until CX=0
        MOV [DI], '$'           ; Store '$' at the end of string

        ; print reversed string
        MOV AH, 09H             ; Store 09H in AH
        LEA DX, revstr          ; Load initial address of register
        INT 21H                 ; Print contents of DX

        ; return control to OS
        MOV AH, 4CH             ; Store 4CH into AH
        INT 21H                 ; Return control to OS

    MAIN ENDP                   ; End procedure
END MAIN                        ; End program
