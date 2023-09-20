#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "binary_output.h"

enum InstructionKind {
    INST_BYTE_DIRECTIVE
};

class Instruction {
public:
    virtual void write_to(BinaryOutput* value);

private:
    int kind;
};

#endif
