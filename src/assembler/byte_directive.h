#ifndef BYTE_DIRECTIVE_H
#define BYTE_DIRECTIVE_H

#include <vector>

#include "instruction.h"
#include "token.h"

class ByteDirective : public Instruction {
public:
    void add_value(Token token);
    void write_to(BinaryOutput* value);

private:
    std::vector<Token> values;
};

#endif
