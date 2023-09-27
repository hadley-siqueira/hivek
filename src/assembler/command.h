#ifndef COMMAND_H
#define COMMAND_H

#include "binary_output.h"

enum CommandKind {
    CMD_BYTE_DIRECTIVE,
    CMD_INT_DIRECTIVE,

    CMD_INST_ADD,
    CMD_INST_ADDI,
};

class Command {
public:
    virtual void write_to(BinaryOutput* value);

protected:
    int kind;
};

#endif
