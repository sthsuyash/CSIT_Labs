; WAP in 8086 to sort the given numbers in ascending order

TITLE SORTING ; TITLE OF THE PROGRAM
.MODEL SMALL ; MODEL OF THE PROGRAM
.STACK
.DATA
    LIST DW 05H, 04H, 01H, 03H, 02H
    COUNT DW 05H
.CODE
    MAIN PROC
        MOV AX, DATA            ; Inititalize data segment
        MOV DS, AX
        MOV DX, COUNT-1         ; Copy values of COUNT-1 to DX
        BACK: MOV CX, DX        ; Copy values of DX to CX
        LEA SI, LIST            ; Load effective address of LIST into SI
        AGAIN: MOV AX, [SI]     ; Copy values of [SI] to AX
        CMP AX, [SI+2]          ; Compare values of AX and [SI+2]
        JC GO;                  ; If carry, goto 'GO'
        XCHG AX, [SI+2]         ; Exchange contents of AX and [SI+2]
        XCHG AX, [SI]           ; Exchange contents of AX and [SI]
        GO : INC SI             ; Increment SI by 1
        INC SI                  ; Increment SI by 1
        LOOP AGAIN              ; Loop to AGAIN until CX=0
        DEC DX                  ; Decrease DX by 1
        JNZ BACK                ; Jump to BACK until DX=0   
    MAIN ENDP                   ; End of procedure
END MAIN                        ; End of program
