#include "section.h"

Section::Section(std::string name) {
    this->name = name;
}

void Section::add_instruction(Instruction* inst) {
    instructions.push_back(inst);
}
