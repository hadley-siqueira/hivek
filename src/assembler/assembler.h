#ifndef HIVEK_ASSEMBLER_H
#define HIVEK_ASSEMBLER_H

#include <cstdint>
#include "../opcodes/opcodes.h"

class Assembler {
    public:

    private:
        void parse_instruction(std::string& inst);

        uint32_t generate_format1(int opcode, int ra, int rb, int rc, int funct);
};

#endif
