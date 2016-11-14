.syntax unified

.text

.align 3
.global decodeChar
.func decodeChar, decodeChar
.type decodeChar, %function

@ char decodeChar(char *b)
decodeChar:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    
    MOV r4, #0  @ counter
    MOV r5, #32  @ power
    MOV r6, #0  @ index
@ use for loop to get the index of the character
for:
    CMP r4, #6
    BGE end
    LDRB r7, [r0, r4]
    CMP r7, #49
    ADDEQ r6, r6, r5
    ADD r4, r4, #1
    ASR r5, r5, #1
    B for

end:
    LDR r8, =MAPPING
    LDRB r0, [r8, r6]

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
