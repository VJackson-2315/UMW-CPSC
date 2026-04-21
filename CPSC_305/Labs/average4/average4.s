@ average4.s

/* function to return the average of four parameter values */
.global	average4
average4:
    add r0, r0, r1 
    add r0, r0, r2 
    add r0, r0, r3
    mov r0, r0, lsr #2
    mov pc, lr

