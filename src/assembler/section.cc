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
