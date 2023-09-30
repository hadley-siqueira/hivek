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
    void define_label(Section* section, Label* label);
    Symbol* resolve(std::string id);

private:
    std::map<std::string, Symbol*> symbols;
    Module* mod;
    int seq;
};

SymbolTable* get_symbol_table();

#endif
