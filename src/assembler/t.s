main:
    add %0, %0, %0

L0:
    add %0, %1, %2
    beq %0, %1, .L0

    .word 0, 1, 2, 3
    .byte 0, 1, 2, 3, 100
