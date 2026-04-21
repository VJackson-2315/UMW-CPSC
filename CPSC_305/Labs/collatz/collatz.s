@ collatz.s

/* function to return the number of steps in the collatz sequence a number produces */
.global	collatz
collatz:
    mov r2, #3
    mov r3, #0
    .top:
        cmp r0, #1
        beq .done
        add r3, r3, #1
        and r1, r0, #1
        cmp r1, #1
        bne .even
        mul r0, r2, r0
        add r0, r0, #1
        b .top  
    .even:
        mov r0, r0, lsr #1
        b .top

    .done:
        mov r0, r3    
        mov pc, lr

