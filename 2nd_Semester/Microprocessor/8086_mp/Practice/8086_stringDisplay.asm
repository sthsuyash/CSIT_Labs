; Display string on the screen

TITLE Display string
.MODEL SMALL
.STACK
.DATA
    D1 DB "Hello World $"
    D2 DB 13, 10, "This is my first program in 8086 $"

.CODE
    MAIN PROC
        ; initialize data segment
        MOV AX, DATA
        MOV DS, AX

        ; first string display
        LEA DX, D1                  ; load effective address of D1 to DX
        MOV AH, O9H                 ; store 09H into AH
        INT 21H                     ; print contents of DX

        ; second string display
        LEA DX, D2                  ; load effective address of D2 to DX
        MOV AH, 09H                 ; store 09H into AH
        INT 21H                     ; print contents of DX

        ; return control to OS
        MOV AH, 4CH                 ; store 4CH into AH
        INT 21H                     ; return control to OS

        MAIN ENDP                   ; end procedure
    END MAIN                        ; end program
