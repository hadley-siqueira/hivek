#include <iostream>
#include <fstream>
#include <sstream>
#include "emulator.h"

Emulator::Emulator() {
    ip = 0;
    clock = 0;

    for (int i = 0; i < 32; ++i) {
        regs[i] = 0;
    }
}

Emulator::~Emulator() {

}

void Emulator::read_bin(std::string path) {
    char c;
    std::ifstream fs;

    fs.open(path);

    while (fs.get(c)) {
        mem.push_back(c & 0x0ff);
    }

    fs.close();

    int i = 0;
    // addi r1, r1, 1
    mem[i++] = 0x81;
    mem[i++] = 0x08;
    mem[i++] = 0x40;
    mem[i++] = 0x01;

    mem[i++] = 0x80;
    mem[i++] = 0x08;
    mem[i++] = 0x42;
    mem[i++] = 0x00;

    mem[i++] = 0x80;
    mem[i++] = 0x08;
    mem[i++] = 0x42;
    mem[i++] = 0x00;
}

void Emulator::dump_memory() {
    for (int i = 0; i < mem.size(); i += 16) {
        std::stringstream ss;
        ss << hex64(i) << "  ";

        for (int j = 0; j < 8 && i + j < mem.size(); ++j) {
            ss << hex8(mem[i + j]) << ' ';
        }

        ss << ' ';

        for (int j = 8; j < 16 && i + j < mem.size(); ++j) {
            ss << hex8(mem[i + j]) << ' ';
        }

        ss << ' ';

        int col = ss.str().size();
        while (col < 68) {
            ++col;
            ss << ' ';
        }

        ss << '|';
        for (int j = 0; j < 16 && i + j < mem.size(); ++j) {
            if (mem[i + j] >= 32 && mem[i + j] <= 126) {
                ss << ((char) (mem[i + j]));
            } else {
                ss << '.';
            }
        }
        ss << '|';

        ss << '\n';
        std::cout << ss.str();
    }
}

void Emulator::dump_registers() {
    for (int i = 0; i < 32; ++i) {
        if (i % 4 == 0 && i > 0) {
            std::cout << '\n';
        }

        std::cout << i << ": ";

        if (i < 10) {
            std::cout << ' ';
        }

        std::cout << hex64(regs[i]) << '\t';
    }

    std::cout << '\n';
}

void Emulator::tick() {
    uint32_t inst = read_u32(ip);
    uint64_t size = 0;

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
    int funct = inst & 0xff;
    int immd14 = inst & 0x3fff;

    regs[0] = 0;
std::cout << inst << std::endl;
std::cout << opcode << ' ' << ra << ' ' << rb << ' ' << rc << std::endl;
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

        case F_AND:
            regs[rc] = regs[ra] & regs[rb];
            ip += size;
            break;

        case F_OR:
            regs[rc] = regs[ra] | regs[rb];
            ip += size;
            break;

        case F_XOR:
            regs[rc] = regs[ra] ^ regs[rb];
            ip += size;
            break;
        }
    } else {
        switch (opcode) {
        case OP_ADDI: // 81084001 = addi r1, r1, 1
            regs[ra] = regs[rb] + immd14;
            ip += size;
            break;

        case OP_LD:
            regs[ra] = read_u64(regs[rb] + immd14);
            ip += size;
            break;
        }
    }
}

uint32_t Emulator::expand(uint32_t inst) {
    return inst;
}

uint64_t Emulator::read_u32(uint64_t addr) {
    uint32_t value = 0;

    value = (value << 8) | (mem[addr + 0] & 0xff);
    value = (value << 8) | (mem[addr + 1] & 0xff);
    value = (value << 8) | (mem[addr + 2] & 0xff);
    value = (value << 8) | (mem[addr + 3] & 0xff);

    return value;
}

uint64_t Emulator::read_i32(uint64_t addr) {
    uint64_t tmp = read_u32(addr);
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

std::string Emulator::hex64(uint64_t value) {
    std::stringstream ss;

    for (int i = 60; i >= 0; i -= 4) {
        int k = (value >> i) & 0xf;

        if (k < 10) {
            ss << ((char) ('0' + k));
        } else {
            ss << ((char) ('a' + k - 10));
        }
    }

    return ss.str();
}

std::string Emulator::hex8(uint64_t value) {
    std::stringstream ss;

    for (int i = 4; i >= 0; i -= 4) {
        int k = (value >> i) & 0xf;

        if (k < 10) {
            ss << ((char) ('0' + k));
        } else {
            ss << ((char) ('a' + k - 10));
        }
    }

    return ss.str();
}
