#include <sstream>
#include <fstream>
#include "assembler.h"
#include "../opcodes/opcodes.h"

void Assembler::parse_instruction(std::string& inst) {
/*    std::stringstream ss(inst);
    std::string opcode;
    std::string op1;
    std::string op2;
    std::string op3;

    ss >> opcode;

    if (opcode == "add") {
        ss >> op1 >> op2 >> op3;
        generate_format1(OP_REG_REG, op1, op2, op3, F_ADD);
    }*/
}

uint32_t Assembler::generate_format1(int opcode, int ra, int rb, int rc, int funct) {
/*    uint32_t inst = 1;

    inst = (inst << 1) | (opcode & 0x7f);
    inst = (inst << 7) | (ra & 0x1f);
    inst = (inst << 5) | (rb & 0x1f);
    inst = (inst << 5) | (rc & 0x1f);
    inst = (inst << 5) | (funct & 0xff);

    return inst;*/
    return 0;
}

/*
    .text
main:
    add %0, %2, %3
    beq %1, %2, .L0

.L0:
    
    .data
    .word 0, 1, 2, 3, 4, 5
    .asciiz "Hello, world"
*/
