; WAP in 8086 to check if the string "Abcdefg" is palindrome or not

TITLE PALINDROME CHECKER
.MODEL SMALL
.STACK
.DATA
    STR DB "Abcdefg$"
    P1 DB 13, 10 "Palindrome$"
    P2 DB 13, 10 "Not Palindrome$"

.CODE
    MAIN PROC
        ; Initialize data segment
        MOV AX, DATA
        MOV DS, AX
        LEA SI, STR             ; Load initial address of STR
        LOOP1: MOV AL, [SI]     ; Copy contents of SI to AL
        CMP AL, '$'             ; Compare AL with '$'
        JE LABEL1               ; Jump to LABEL1 if equal
        INC SI                  ; Increase SI by 1
        JMP LOOP1               ; Jump to LOOP1
        LABEL1: LEA DI, STR     ; Load initial address of STR
        DEC SI                  ; Decrease SI by 1
        L1: CMP SI, DI          ; Compare SI and DI
        JL PO1                  ; Jump to PO1 if SI < DI
        MOV AL, [SI]            ; Copy SI to AL
        MOV BL, [DI]            ; Copy DI to BL
        CMP AL, BL              ; Compare AL and BL
        JNE PO2                 ; Jump to PO2 if RL != BL
        DEC SI                  ; Decrease SI by 1
        JNC DI                  ; Increase DI by 1
        JMP L1                  ; Jump to L1

        PO1:
        LEA DX, P1              ; Load initial address of P1
        MOV AH, 09H             ; Copy 09H to AH
        INT 21H                 ; Print contents of DX
        JMP P0                  ; Jump to P0

        PO2:
        LEA DX, P2              ; Load initial address of P2
        MOV AH, 09H             ; Copy 09H to AH
        INT 21H                 ; Print contents of DX
        JMP P0                  ; Jump to P0

        PO:
        MOV AH, 4CH             ; Store 4CH into AH
        INT 21H                 ; Return control to OS

    MAIN ENDP                        ; End Procedure
END MAIN                        ; End Program