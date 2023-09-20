#ifndef DATA_DIRECTIVE_H
#define DATA_DIRECTIVE_H

#include <vector>

#include "command.h"
#include "token.h"

class DataDirective : public Command {
public:
    DataDirective(int kind);

public:
    void add_value(Token token);
    void write_to(BinaryOutput* value);
    void write_byte_directive(BinaryOutput* value);

private:
    std::vector<Token> values;
};

#endif
