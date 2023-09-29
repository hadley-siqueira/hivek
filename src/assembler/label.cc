#include "label.h"

Label::Label(std::string value) {
    this->value = value;
    this->kind = CMD_LABEL;
}

void Label::set_offset(int value) {
    offset = value;
}
