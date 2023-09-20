#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <vector>

#include "instruction.h"
#include "binary_output.h"

class Section {
public:
    Section(std::string name);

public:
    void add_instruction(Instruction* inst);
    void write_to(BinaryOutput* value);

private:
    std::string name;
    std::vector<Instruction*> instructions;
};

#endif
