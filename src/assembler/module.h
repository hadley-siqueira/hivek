#ifndef MODULE_H
#define MODULE_H

#include <map>
#include <string>

#include "section.h"
#include "command.h"
#include "binary_output.h"

class Module {
public:
    Module();
    
public:
    void add_to_section(Command* cmd);
    void write_to(BinaryOutput* value);
    void set_section(std::string section);
    Section* get_current_section();
    void first_pass();

private:
    std::map<std::string, Section*> sections;
    std::string current_section;
    BinaryOutput* output;
};

#endif
