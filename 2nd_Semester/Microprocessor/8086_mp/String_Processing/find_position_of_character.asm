; WAP in 8086 to find the program of position of first occurence of the character 'a' in the string
; "Programming in 8086 is very much important."

TITLE FIND POSITION
.MODEL SMALL
.STACK
.DATA
    SRT DB "Programming in 8086 is very much important.$"
.CODE
    MAIN PROC
        MOV AX, DATA            ; Initialize data segment
        MOV DS, AX              ; Move AX into DS
        LEA SI, SRT             ; Load initial address of SRT
        LOOP1: MOV AL, [SI]     ; Copy contents of SI into AL
        CMP AL, 'a'             ; Compare AL with 'a'
        JE L1                   ; Jump to L1 if AL = 'a'
        INC SI                  ; Increase value of SI by 1
        JMP LOOP1               ; Jump to LOOP1
        L1: INC SI              ; Increase value of SI by 1
        MOV BX, SI              ; Copy contents of SI into BX [Position of first occurence]
    MAIN ENDP                        ; End procedure
END MAIN                        ; End program
