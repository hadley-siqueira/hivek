#include "align_directive.h"

AlignDirective::AlignDirective() {
    kind = CMD_ALIGN_DIRECTIVE;
    set_value(1);
}

AlignDirective::AlignDirective(int value) {
    kind = CMD_ALIGN_DIRECTIVE;
    set_value(value);
}

void AlignDirective::set_value(int v) {
    value = v;
}

void AlignDirective::write_to(BinaryOutput* value) {
    while (value->size() % this->value != 0) {
        value->append(0);
    }
}

int AlignDirective::get_value() {
    return value;
}
