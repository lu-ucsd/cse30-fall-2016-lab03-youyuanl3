.syntax unified

.text

.align 3
.global decodeFile
.func decodeFile, decodeFile
.type decodeFile, %function
 
@ void decodeFile(char *input, char *bin, char * output, int index)
decodeFile:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    
    @ fopen(input, "r")
    PUSH {r0-r3, r12}
    LDR r1, =read
    BL fopen
    MOV r4, r0
    POP {r0-r3, r12}

    CMP r4, #0
    BEQ return  @ invalid input

    @ fopen(bin, "w")
    PUSH {r0-r3, r12}
    MOV r0, r1
    LDR r1, =write
    BL fopen
    MOV r5, r0
    POP {r0-r3, r12}

    @ codeToBinary
    PUSH {r0-r3, r12}
    MOV r0, r4
    MOV r1, r5
    MOV r2, r3
    BL codeToBinary
    POP {r0-r3, r12}

    PUSH {r0-r3, r12}
    MOV r0, r4
    BL fclose
    POP {r0-r3, r12}

    PUSH {r0-r3, r12}
    MOV r0, r5
    BL fclose
    POP {r0-r3, r12}

    @ fopen(bin, "r")
    PUSH {r0-r3, r12}
    MOV r0, r1
    LDR r1, =read
    BL fopen
    MOV r4, r0
    POP {r0-r3, r12}

    @ fopen(output, "w")
    PUSH {r0-r3, r12}
    MOV r0, r2
    LDR r1, =write
    BL fopen
    MOV r5, r0
    POP {r0-r3, r12}

    @ binaryToText
    PUSH {r0-r3, r12}
    MOV r0, r4
    MOV r1, r5
    BL binaryToText
    POP {r0-r3, r12}

    PUSH {r0-r3, r12}
    MOV r0, r4
    BL fclose
    POP {r0-r3, r12}

    PUSH {r0-r3, r12}
    MOV r0, r5
    BL fclose
    POP {r0-r3, r12}
    
.data 
read:
    .asciz "r"
write:
    .asciz "w"

.text

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
