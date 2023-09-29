#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include "symbol.h"
#include "label.h"
#include "module.h"

class SymbolTable {
public:
    SymbolTable();
    
public:
    void define_label(Label* label);

private:
    std::map<std::string, Symbol*> symbols;
    Module* mod;
    int seq;
};


#endif
