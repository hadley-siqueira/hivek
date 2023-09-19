#include "module.h"

Module::Module() {
    current_section = "text";
    sections["text"] = new Section("text");
}

void Module::add_to_section(Instruction* inst) {
    sections[current_section]->add_instruction(inst);
}
