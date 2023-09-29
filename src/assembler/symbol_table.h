#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include "symbol.h"
#include "label.h"

class SymbolTable {
public:
    void define_label(Label* label);

private:
    std::map<std::string, Symbol*> symbols;   
};


#endif
