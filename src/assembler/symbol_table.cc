#include "symbol_table.h"

SymbolTable symbol_table;

SymbolTable::SymbolTable() {
    seq = 0;
    mod = nullptr;
}

void SymbolTable::define_label(Section* section, Label* label) {
    std::string name = label->get_value();
    Symbol* sym = new Symbol(name, section, label->get_offset(), true, seq);
    symbols[name] = sym;
    seq += 1;
}

Symbol* SymbolTable::resolve(std::string id) {
    if (symbols.count(id)) {
        return symbols[id];
    }

    return nullptr;
}

SymbolTable* get_symbol_table() {
    return &symbol_table;
}
