#ifndef COMMAND_H
#define COMMAND_H

#include "binary_output.h"

enum CommandKind {
    CMD_LABEL,

    CMD_BYTE_DIRECTIVE,
    CMD_INT_DIRECTIVE,
    CMD_ALIGN_DIRECTIVE,

    CMD_INST_ADD,
    CMD_INST_SUB,

    CMD_INST_AND,
    CMD_INST_OR,
    CMD_INST_XOR,

    CMD_INST_BEQ,

    CMD_INST_ADDI,
};

class Command {
public:
    int get_kind();
    virtual void write_to(BinaryOutput* value);
    virtual int get_size();

protected:
    int kind;
};

#endif
