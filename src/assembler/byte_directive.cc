#include <iostream>
#include <sstream>
#include "byte_directive.h"

void ByteDirective::add_value(Token token) {
    values.push_back(token);
}

void ByteDirective::write_to(BinaryOutput* value) {
    for (int i = 0; i < values.size(); ++i) {
        std::stringstream ss;
        int v;

        ss << values[i].get_lexeme();
        ss >> v;
        std::cout << ".. " << v << '\n';
        value->append(v);
    }
}
