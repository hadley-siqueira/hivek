    sub %1, %1, %1
    addi %2, %1, 10
L0:
    beq %1, %2, L1
    addi %1, %1, 1
    beq %1, %1, L0

L1:
    beq %1, %1, L1
