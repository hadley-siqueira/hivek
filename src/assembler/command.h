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

    CMD_INST_LD,
    CMD_INST_LW,
    CMD_INST_LWU,

    CMD_INST_SD,
    CMD_INST_SW,
    CMD_INST_SH,
    CMD_INST_SB,

    CMD_INST_ADDI,
};

class Command {
public:
    int get_kind();
    virtual void write_to(BinaryOutput* value);
    virtual int get_size();
    int get_offset();
    void set_offset(int offset);

protected:
    int kind;
    int offset;
};

#endif
