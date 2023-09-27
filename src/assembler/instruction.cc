#include "instruction.h"

Instruction::Instruction(int kind) {
    this->kind = kind;
}

void Instruction::set_r_dest(int r) {
    r_dest = r;
}

void Instruction::set_r_src1(int r) {
    r_src1 = r;
}

void Instruction::set_r_src2(int r) {
    r_src2 = r;
}

void Instruction::write_to(BinaryOutput* value) {
    int inst = 0;

    switch (kind) {
    case CMD_INST_ADD:
        write_binary_type_i(value, F_ADD);
        break;
    }
}

void Instruction::write_binary_type_i(BinaryOutput* value, int func) {
    int inst = get_binary_type_i(func);
    value->append32(inst);
}

int Instruction::get_binary_type_i(int func) {
    int inst = 0;

    inst = 1;
    inst = inst << 7 | OP_REG_REG;
    inst = inst << 5 | r_src1;
    inst = inst << 5 | r_src2;
    inst = inst << 5 | r_dest;
    inst = inst << 9 | func;

    return inst;
}
