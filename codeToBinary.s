.syntax unified

.text

.align 3
.global codeToBinary
.func codeToBinary, codeToBinary
.type codeToBinary, %function

@void codeToBinary(FILE *in, FILE *out, int index);

codeToBinary:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    
    CMP r0, #0
    BEQ return  @ invalid input

    MVN r11, #0
@ use while loop to traverse all characters
while:
    PUSH {r0-r3, r12}
    BL fgetc  @ get a character from code file
    MOV r4, r0
    POP {r0-r3, r12}
    CMP r4, r11  @ check if EOF is encountered
    BEQ return

    PUSH {r0-r3, r12}
    MOV r0, r4
    MOV r1, r2
    BL extractBit  @ extract the bit from the character
    MOV r5, r0
    POP {r0-r3, r12}

    CMP r5, #1  @ check the value of the bit
    MOVEQ r6, #49
    MOVNE r6, #48

    PUSH {r0-r3, r12}
    MOV r0, r6
    BL fputc  @ put the bit in the binary file
    POP {r0-r3, r12}

    B while

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
