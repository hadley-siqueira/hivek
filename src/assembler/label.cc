#include "label.h"

Label::Label(std::string value) {
    this->value = value;
    this->kind = CMD_LABEL;
}

void Label::set_offset(int value) {
    offset = value;
}

std::string Label::get_value() {
    return value;
}
