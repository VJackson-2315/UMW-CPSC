@ uppercase.s

/* function to convert a given string to all uppercase */
.global	uppercase
uppercase:
    sub sp, sp, #4
    str lr, [sp]
    mov r4, r0
    mov r1, #0

.top:    
    ldrb r0, [r4, r1]
    cmp r0, #0
    beq .done
    bl toupper
    strb r0, [r4, r1]
    add r1, r1, #1
    b .top

.done:   
    ldr r0, [r4]
    ldr lr, [sp]
    add sp, sp, #4
    mov pc, lr
