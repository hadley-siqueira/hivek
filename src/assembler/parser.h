#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "instruction.h"
#include "token.h"
#include "module.h"

class Parser {
public:
    Module* parse(std::string path);

private:
    Module* parse_module();

    Instruction* parse_directive();
    Instruction* parse_byte_directive();
    void parse_string_directive();

    Token parse_byte_literal();

private:
    bool match(int kind);
    bool match(std::string lexeme);
    void expect(int kind);
    void expect(std::string lexeme);
    bool lookahead(int kind);
    bool lookahead(std::string lexeme);
    void advance();

private:
    std::vector<Token> tokens;
    Token matched;
    int idx;
};

#endif
