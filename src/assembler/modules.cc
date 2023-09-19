#include "modules.h"

void Modules::add_module(Module* mod) {
    modules.push_back(mod);
}

Module* Modules::get_module(int idx) {
    return modules[idx];
}

int Modules::modules_count() {
    return modules.size();
}
