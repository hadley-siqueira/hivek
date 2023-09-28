#ifndef ALIGN_DIRECTIVE_H
#define ALIGN_DIRECTIVE_H

#include "command.h"

class AlignDirective : public Command {
public:
    AlignDirective();
    AlignDirective(int value);

public:
    void set_value(int v);
    void write_to(BinaryOutput* value);

private:
    int value;
};

#endif
