#include <iostream>
#include "section.h"
#include "align_directive.h"

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

void Section::first_pass() {
    calculate_offsets();
}

void Section::calculate_offsets() {
    int offset = 0;

    for (int i = 0; i < commands.size(); ++i) {
        Command* cmd = commands[i];

        cmd->set_offset(offset);

        if (cmd->get_kind() == CMD_LABEL) {
            Label* label = (Label*) cmd;
            std::cout << label->get_value() << ":" << offset << '\n';
        } else if (cmd->get_kind() == CMD_ALIGN_DIRECTIVE) {
            AlignDirective* align = (AlignDirective*) cmd;

            while (offset % align->get_value() != 0) {
                offset += 1;
            }
        }

        offset += cmd->get_size();
    }
}

std::string Section::get_name() {
    return name;
}
