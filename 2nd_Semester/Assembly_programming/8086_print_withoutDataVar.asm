; print your name without using data variable

TITLE Print Name
.MODEL SMALL
.STACK
.DATA
    BUFFERSIZE DB 100
    BUFFER DB 100 DUP("$")
.CODE
    MAIN PROC
        ; initialize data segment
        MOV AX, @DATA
        MOV DS, AX
        ; take name from user
        LEA DX, BUFFER      ; load effective address of BUFFER 
        MOV AH, 0AH         ; store 0AH at AH
        INT 21H             ; store input at BUFFERSIZE

        ; print output (name)
        LEA DX, BUFFER      ; load effective address of BUFFER
        MOV AH, 09H         ; store 09H at AH
        INT 21H             ; print name from BUFFER

        ; return control to OS
        MOV AH, 4CH         ; store 4CH at AH
        INT 21H             ; return control to OS         
        MAIN ENDP           ; end main procedure
    END MAIN                ; end program