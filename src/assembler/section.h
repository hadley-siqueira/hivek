#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <vector>

#include "command.h"
#include "binary_output.h"

class Section {
public:
    Section(std::string name);

public:
    void add_command(Command* cmd);
    void write_to(BinaryOutput* value);

private:
    std::string name;
    std::vector<Command*> commands;
};

#endif
