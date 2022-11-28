; WAP in 8086 to take a single character input from keyboard and display it on the screen

TITLE PRINT SINGLE CHARACTER 
.MODEL SMALL
.STACK
.DATA
.CODE
    MAIN PROC
        ; take character input 
        MOV AH, 01H     ; Store 01H at AH register
        INT 21H         ; Store character in AL register

        ; print 
        MOV DL, AL      ; Move contents of AL to DL
        MOV AH, 02H     ; Store 02H at AH register
        INT 21H         ; Print the character

        ; Return control to OS
        MOV AH, 4CH     ; Store 4CH at AH
        INT 21H         ; Return control to OS
        
    MAIN ENDP           ; End the procedure
END MAIN                ; End program
