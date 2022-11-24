; Write an assembly language program
; to load register D with data FFH and 
; copy the content of this memory location to register C.

MVI D, FFH  ; Load D with FFH immediately
MOV C, D    ; Copy content of register D to register C
HLT         ; stop the program
