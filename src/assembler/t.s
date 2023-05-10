main:
    add a, b, c
    beq a, b, immd
    add %0, %1, %2

    .word 0, 1, 2, 3
    .byte 0, 1, 2, 3, 100
