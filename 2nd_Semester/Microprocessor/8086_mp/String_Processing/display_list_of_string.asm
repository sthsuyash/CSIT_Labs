; WAP in 8086 to display:
; "Hello World."
; "This is my first program in 8086."
; "Let's keep in touch."

TITLE PRINT
.MODEL SMALL
.STACK
.DATA
    D1 DB "Hello World$"
    D2 DB 13, 10, "This is my first program in 8086.$"
    D3 DB 13, 10, "Let's keep in touch.$"

.CODE
    MAIN PROC
        ; Initialize Data Segment
        MOV AX, DATA
        MOV DS, AX

        ; First string print
        LEA DX, D1  ; Load effective address of D1 to DX
        MOV AH, 09H ; Store 09H into AH
        INT 21H     ; Print contents of DX

        ; Second string print
        LEA DX, D2  ; Load effective address of D2 to DX
        MOV AH, 09H ; Store 09H into AH
        INT 21H     ; Print contents of DX

        ; Third string print 
        LEA DX, D3  ; Load effective address of D2 to DX
        MOV AH, 09H ; Store 09H into AH
        INT 21H     ; Print contents of DX

        ; return control to OS
        MOV AH, 4CH ; Store 4CH into AH
        INT 21H     ; Return control to OS

    MAIN ENDP       ; End procedure
END MAIN            ; End program
