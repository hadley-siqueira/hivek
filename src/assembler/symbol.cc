#include "symbol.h"

Symbol::Symbol(std::string name, Section* section, int offset, bool local, int seq) {
    this->name = name;
    this->section = section;
    this->offset = offset;
    this->local = local;
    this->seq = seq;
}

int Symbol::get_kind() {
    return kind;
}

void* Symbol::get_descriptor() {
    return descriptor;
}

