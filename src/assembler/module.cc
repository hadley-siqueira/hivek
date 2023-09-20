#include "module.h"

Module::Module() {
    current_section = "text";
    sections["text"] = new Section("text");
}

void Module::add_to_section(Instruction* inst) {
    sections[current_section]->add_instruction(inst);
}

void Module::write_to(BinaryOutput* value) {
    output = value;

    for (auto it = sections.begin(); it != sections.end(); ++it) {
        Section* section = it->second;
        section->write_to(output);
    }
}
