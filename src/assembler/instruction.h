#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction {
    public:
        uint32_t to_bin32();

    private:
        char opcode;
        char funct;
        char op1;
        char op2;
        char op3;
        int size;
        int offset;
};

#endif
