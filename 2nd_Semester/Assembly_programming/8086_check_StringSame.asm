; Read the string and check whether they are same or not

TITLE Read strings and check for equality
.MODEL SMALL
.STACK
.DATA
    CR EQU 13
    LF EQU 10
    INMSG1  DB CR,LF,”ENTER THE STRING1: $”
    INMSG2  DB CR,LF,LF,”ENTER THE STRING2: $”
    STRNG1  DB 0BH,12 DUP("?")
    STRNG2  DB 0BH,12 DUP("?")
    SUCMSG  DB CR,LF,LF,”BOTH ARE SAME $”
    FALMSG  DB CR,LF,LF,”DIFFERENT STRINGS $”

.CODE

ASSUME CS:CODE, DS:DATA
    MAIN PROC
        ;initialize data segment
        START:  MOV AX, DATA
        MOV DS,AX
        MOV ES,AX

        LEA DX, INMSG1              ; load effective address of INMSG1 to DX.
        MOV AH, 09                  ; store 09H into AH.
        INT 21H                     ; print contents of DX.

        MOV DX, OFFSET STRNG1       ; load effective address of STRING1 to DX.
        MOV AH, 0AH                 ; store 0AH into AH.
        INT 21H                     ; input

        LEA DX, INMSG2              ; load effective address of INMSG2 to DX.
        MOV AH, 09H                 ; store 09H into AH.
        INT 21H                     ; print contents of DX.

        MOV DX, OFFSET STRNG2       ; load effective address of STRING2 to DX.
        MOV AH, 0AH                 ; store 0AH into AH.
        INT 21H                     ; input

        MOV SI, OFFSET STRNG1       ; copy contents of STRING1 to SI.
        MOV DI, OFFSET STRNG2       ; copy contents of STRING2 to DI.
        CLD                         ; clear direction flag
        MOV CX, 06H                 ; store 06H into CX.
        JZ SUCCESS                  ; jump if zero flag is set to label 'SUCCESS'.

        LEA DX, FALMSG              ; load effective address of FALMSG to DX.
        JMP DISPLAY                 ; jump to label 'DISPLAY'
        SUCCESS: LEA DX,SUCMSG      ; store effective address of SUCMSG to DX.
        DISPLAY: MOV AH, 09H         ; store 09H into AH.
        INT 21H                     ; print

        ; return control to OS
        MOV AH,4CH                  ; store 4CH at AH
        INT 21H                     ; return control to OS

        END START                   ; end start
        MAIN ENDP                   ; end main procedure
    END MAIN                        ; end program