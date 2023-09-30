#include "label.h"

Label::Label(std::string value) {
    this->value = value;
    this->kind = CMD_LABEL;
}

std::string Label::get_value() {
    return value;
}
