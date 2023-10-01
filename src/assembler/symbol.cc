#include "symbol.h"

Symbol::Symbol(int kind, std::string name, Section* section, int offset, bool local, int seq) {
    this->name = name;
    this->section = section;
    this->offset = offset;
    this->local = local;
    this->seq = seq;
    this->kind = kind;
}

int Symbol::get_kind() {
    return kind;
}

void* Symbol::get_descriptor() {
    return descriptor;
}

void Symbol::set_descriptor(void* descriptor) {
    this->descriptor = descriptor;
}
