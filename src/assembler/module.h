#ifndef MODULE_H
#define MODULE_H

#include <map>
#include <string>

#include "section.h"
#include "instruction.h"

class Module {
public:
    Module();
    
public:
    void add_to_section(Instruction* inst);
    void write_to(std::vector<char>& output);

private:
    std::map<std::string, Section*> sections;
    std::string current_section;
};

#endif
