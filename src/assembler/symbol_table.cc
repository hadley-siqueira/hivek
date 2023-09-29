#include "symbol_table.h"

SymbolTable::SymbolTable() {
    seq = 0;
    mod = nullptr;
}

void SymbolTable::define_label(Label* label) {
    Section* section = mod->get_current_section();
    sym = new Symbol(label->get_value(), section->get_name(), section->get_offset(), true, seq);
}
