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

    case CMD_INT_DIRECTIVE:
        write_int_directive(value);
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

void DataDirective::write_int_directive(BinaryOutput* value) {
    for (int i = 0; i < values.size(); ++i) {
        std::stringstream ss;
        int v;

        ss << values[i].get_lexeme();
        ss >> v;
        value->append((v >> 24) & 0xff);
        value->append((v >> 16) & 0xff);
        value->append((v >> 8) & 0xff);
        value->append((v >> 0) & 0xff);
    }
}

int DataDirective::get_size() {
    switch (kind) {
    case CMD_BYTE_DIRECTIVE:
        return values.size() * 1;

    case CMD_INT_DIRECTIVE:
        return values.size() * 4;
    }

    return 0;
}

