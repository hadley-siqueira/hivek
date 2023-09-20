#include <iostream>
#include "section.h"

Section::Section(std::string name) {
    this->name = name;
}

void Section::add_instruction(Instruction* inst) {
    instructions.push_back(inst);
}

void Section::write_to(BinaryOutput* value) {
    for (int i = 0; i < instructions.size(); ++i) {
        instructions[i]->write_to(value);
    }
}
