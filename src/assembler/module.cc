#include "module.h"

Module::Module() {
    current_section = "text";
    sections["text"] = new Section("text");
}

void Module::add_to_section(Command* cmd) {
    sections[current_section]->add_command(cmd);
}

void Module::set_section(std::string section) {
    if (sections.count(section) == 0) {
        sections[section] = new Section(section);
    }

    current_section = section;
}

void Module::write_to(BinaryOutput* value) {
    output = value;

    for (auto it = sections.begin(); it != sections.end(); ++it) {
        Section* section = it->second;
        section->write_to(output);
    }
}
