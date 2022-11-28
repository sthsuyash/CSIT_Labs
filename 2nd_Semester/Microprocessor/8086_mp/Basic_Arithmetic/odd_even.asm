; WAP in 8086 to separate odd and even numbers

TITLE SEPARATE ODD AND EVEN NUMBERS
.MODEL SMALL
.STACK
.DATA
    LIST DW 1,2,3,4,5,6,7,8,9
    ODD DW 10 DUP(?)
    EVEN DW 10 DUP(?)
    COUNT DW 9

.CODE
    MAIN PROC
        ; Initializing data segment
        MOV AX, DATA
        MOV DI, AX
        MOV CX, COUNT       ; Copy content count in CX for counter
        LEA SI, LIST        ; Load effective address of list into SI
        L1: MOV AX, [SI]    ; Copy contents of SI into AX
        MOV BX, AX          ; Copy contents of AX into BX
        AND AX, 0001H       ; AND contents of AX with 0001H
        CMP AX, 0001H       ; Compare contents of AX with 0001H
        JE SKIP             ; If equal, jump to SKIP
        MOV EVEN, BX        ; Copy to EVEN, contents of BX
        JMP HERE            ; Jump to HERE 
        SKIP: MOV ODD, BX   ; Copy contents to ODD if equal
        HERE: INC SI        ; Increase SI by 1
        INC SI              ; Increase SI by 1
        LOOP L1             ; Jump to l1 until CX=0
    MAIN ENDP               ; End procedure
END MAIN                    ; End the program
