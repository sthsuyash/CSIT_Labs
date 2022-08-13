; Reverse the number stored in one block and store in another

; reverse the number stored in one block
LXI B, 1122H    ; load 1122H into B-C register.
LXI SP, 0002H   ; initialize stack with 0002H.
PUSH B          ; at [0000H], 22H is stored.
POP D           ; at [0001H], 11H is stored.
MOV H, D        ; load D with [0001H], i.e, 11H.
MOV D, E        ; load E with [0000H], i.e, 22H.
PUSH D          ; 11H is stored at [0000H], i.e, [D].
                ; 22H is stored at [0001H], i.e, [E]

; COPY BLOCK OF MEMORY TO ANOTHER MEMORY LOCATION
LXI D, 0002H    ; load 0002H into D-E register pair.
LXI H, 0000H    ; load 0000H into H-L register pair.
MOV B,M         ; copy contents of memory location pointed by H-L pair to B register.
LOOP: INX H     ; increase value of H-L pair by 1.
MOV A, M        ; copy contents of memory into accumulator.
STAX D          ; store contents of A into address designated by D-E pair.
INX D           ; increase value of D-E pair by 1.
DCR B           ; decrease value of B by 1.
JNZ LOOP        ; jump to label 'LOOP' if zero flag is not set.
HLT             ; stop the program
