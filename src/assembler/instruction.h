#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "command.h"
#include "../opcodes/opcodes.h"

class Instruction : public Command {
public:
    Instruction(int kind);

public:
    void write_to(BinaryOutput* value);
    void write_binary_type_i(BinaryOutput* value, int func);
    int get_binary_type_i(int func);

public:
    void set_r_dest(int r);
    void set_r_src1(int r);
    void set_r_src2(int r);

private:
    char r_dest;
    char r_src1;
    char r_src2;
};

#endif
