.syntax unified

.text

.align 3
.global binaryToText
.func binaryToText, binaryToText
.type binaryToText, %function

@ void binaryToText(FILE *in, FILE *out)
binaryToText:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    
    CMP r0, #0
    BEQ return  @ invalid input

    PUSH {r0-r3, r12}
    MOV r0, #6
    BL malloc   @ malloc an array of size 6
    MOV r4, r0
    POP {r0-r3, r12}

    CMP r4, #0
    BEQ return  @ malloc unsuccessful

    MVN r11, #0
@ use while loop to traverse all characters
while:
    PUSH {r0-r3, r12}
    BL fgetc
    MOV r5, r0
    POP {r0-r3, r12}
    CMP r5, r11
    BEQ end  @ check if EOF is encountered
 
    STRB r5, [r4]
    MOV r6, #1
@ use for loop to get the array
for:
    CMP r6, #6
    BGE endfor
    PUSH {r0-r3, r12}
    BL fgetc
    MOV r5, r0
    POP {r0-r3, r12}
    STRB r5, [r4, r6]
    ADD r6, r6, #1
    B for

endfor:
    PUSH {r0-r3, r12}
    MOV r0, r4
    BL decodeChar  @ decode the array
    MOV r7, r0
    POP {r0-r3, r12}

    PUSH {r0-r3, r12}
    MOV r0, r7
    BL fputc  @ print the character
    POP {r0-r3, r12}
    B while

end:
    PUSH {r0-r3, r12}
    MOV r0, r4
    BL free
    POP {r0-r3, r12}

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
