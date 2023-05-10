#ifndef HIVEK_EMULATOR_H
#define HIVEK_EMULATOR_H

#include <string>
#include <vector>
#include <cstdint>
#include "../opcodes/opcodes.h"

class Emulator {
    public:
        Emulator();
        ~Emulator();

    public:
        void read_bin(std::string path);

        void dump_memory();
        void dump_registers();
        void tick();

    private:

        uint32_t expand(uint32_t inst);

    private:
        uint64_t read_u32(uint64_t addr);
        uint64_t read_i32(uint64_t addr);

        uint64_t read_u64(uint64_t addr);

    private:
        std::string hex64(uint64_t value);
        std::string hex8(uint64_t value);

    private:
        uint64_t ip;
        int64_t regs[32];
        uint8_t* mem;
        size_t mem_size;
        uint64_t clock;
};

#endif
