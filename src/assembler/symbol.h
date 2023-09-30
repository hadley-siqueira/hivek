#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

enum SymbolKind {
    SYM_LABEL
};

class Section;

class Symbol {
public:
    Symbol(std::string name, Section* section, int offset, bool local, int seq);

public:
    int get_kind();
    void* get_descriptor();

private:
    int kind;
    std::string name;
    int seq;
    int offset;
    bool local;
    Section* section;
    void* descriptor;
};

#endif
