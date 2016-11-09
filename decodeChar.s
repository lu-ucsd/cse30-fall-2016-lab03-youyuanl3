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
    


    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
