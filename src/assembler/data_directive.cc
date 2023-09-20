#include <iostream>
#include <sstream>
#include "data_directive.h"

DataDirective::DataDirective(int kind) {
    this->kind = kind;
}

void DataDirective::add_value(Token token) {
    values.push_back(token);
}

void DataDirective::write_to(BinaryOutput* value) {
    switch (kind) {
    case CMD_BYTE_DIRECTIVE:
        write_byte_directive(value);
        break;
    }
}

void DataDirective::write_byte_directive(BinaryOutput* value) {
    for (int i = 0; i < values.size(); ++i) {
        std::stringstream ss;
        int v;

        ss << values[i].get_lexeme();
        ss >> v;
        value->append(v);
    }
}
