#ifndef MODULES_H
#define MODULES_H

#include <vector>
#include "module.h"

class Modules {
public:
    void add_module(Module* mod);
    Module* get_module(int idx);
    int modules_count();

private:
    std::vector<Module*> modules;
};

#endif
