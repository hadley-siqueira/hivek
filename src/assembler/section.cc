#include <iostream>
#include "section.h"

Section::Section(std::string name) {
    this->name = name;
}

void Section::add_command(Command* cmd) {
    commands.push_back(cmd);
}

void Section::write_to(BinaryOutput* value) {
    for (int i = 0; i < commands.size(); ++i) {
        commands[i]->write_to(value);
    }
}

void Section::calculate_offsets() {
    int offset = 0;

    for (int i = 0; i < commands.size(); ++i) {
        Command* cmd = commands[i];

        if (cmd->get_kind() == CMD_LABEL) {
            Label* label = (Label*) cmd;
            label->set_offset(offset);
        } 

        offset += cmd->get_size();
    }
}
