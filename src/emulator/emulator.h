#ifndef HIVEK_EMULATOR_H
#define HIVEK_EMULATOR_H

#include <cstdint>

class Emulator {
    public:
        Emulator();
        ~Emulator();

    private:
        void fetch();

        uint32_t expand(uint32_t inst);

    private:
        uint64_t read_u32(uint64_t addr);
        uint64_t read_i32(uint64_t addr);

        uint64_t read_u64(uint64_t addr);

    private:
        uint64_t ip;
        int64_t regs[32];
        uint8_t* mem;
        uint64_t clock;
};

#endif
