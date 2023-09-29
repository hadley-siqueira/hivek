std.io.File#init(int):
    add %1, %0, %0
    sub %1, %0, %0
    and %1, %0, %0
    or %1, %0, %0
    xor %1, %0, %0
    add %7, %7, %7
    addi %1, %1, 7
L0:

    beq %1, %1, 4
    beq %1, %1, -4
    beq %1, %1, L0

std.io.println(std.io.String):
    .int 1024, 19114957

