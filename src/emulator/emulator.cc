#include "emulator.h"

Emulator::Emulator() {
    mem = nullptr;
    ip = 0;
    clock = 0;

    for (int i = 0; i < 32; ++i) {
        regs[i] = 0;
    }
}

Emulator::~Emulator() {
    delete[] mem;
}

void Emulator::fetch() {
    uint32_t inst = read_u32(ip);
    uint64_t size = 0;
    int opcode = 0;

    if (inst & (1 << 31)) {
        size = 4;
    } else {
        inst = expand(inst);
        size = 2;
    }

    int opcode = (inst >> 24) & 0x7f;
    int ra = (inst >> 19) & 0x1f;
    int rb = (inst >> 14) & 0x1f;
    int rc = (inst >> 9) & 0x1f;

    if (opcode == OP_REG_REG) {
        switch (funct) {
        case F_ADD:
            regs[rc] = regs[ra] + regs[rb];
            ip += size;
            break;

        case F_SUB:
            regs[rc] = regs[ra] - regs[rb];
            ip += size;
            break;
        }
    }
}

uint64_t Emulator::read_u32(uint64_t addr) {
    uint64_t value = read_u64(addr);

    return value & 0xffffffff;
}

uint64_t Emulator::read_i32(uint64_t addr) {
    uint64_t tmp = read_u64(addr);
    uint64_t value = 0;

    if ((tmp >> 31) & 1) {
        value = 0xffffffff;
    }

    value = (value << 32) | tmp;
    return value;
}

uint64_t Emulator::read_u64(uint64_t addr) {
    uint64_t value = 0;

    value = (value << 8) | (mem[addr + 0] & 0xff);
    value = (value << 8) | (mem[addr + 1] & 0xff);
    value = (value << 8) | (mem[addr + 2] & 0xff);
    value = (value << 8) | (mem[addr + 3] & 0xff);
    value = (value << 8) | (mem[addr + 4] & 0xff);
    value = (value << 8) | (mem[addr + 5] & 0xff);
    value = (value << 8) | (mem[addr + 6] & 0xff);
    value = (value << 8) | (mem[addr + 7] & 0xff);

    return value;
}
