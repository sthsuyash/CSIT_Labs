; WAP in 8086 to print your name without using data variable

TITLE PRINT NAME
.MODEL SMALL
.STACK
.DATA
    BUFFERSIZE DB 100
    BUFFER DB 100 DUP("$")

.CODE
    MAIN PROC

        ; Initializing data segment
        MOV AX, @DATA
        MOV DS, AX

        ; Take name from user
        LEA DX, BUFFER      ; Load effective address of BUFFER
        MOV AH, 0AH         ; Store 0AH at AH
        INT 21H             ; Store input at Buffersize 

        ; Print output(name)
        LEA DX, BUFFER      ; Load effective address of BUFFER
        MOV AH, 09H         ; Store 09H at AH
        INT 21H             ; Print name from Buffer 

        ; Return control of OS
        MOV AH, 4CH         ; Store 4CH at AH
        INT 21H             ; Return control to OS

    MAIN ENDP
END MAIN
