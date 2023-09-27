#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "command.h"
#include "token.h"
#include "value.h"
#include "module.h"

class Parser {
public:
    Parser();

public:
    Module* parse(std::string path);

private:
    Module* parse_module();

    Command* parse_directive();
    Command* parse_byte_directive();
    Command* parse_int_directive();
    Command* parse_label_or_instruction();
    Command* parse_instruction(std::string op);
    Command* parse_instruction_reg_reg_reg(int kind);
    Command* parse_instruction_reg_reg_immd(int kind);
    Value* parse_register();
    void parse_string_directive();

    Token parse_byte_literal();
    Token parse_int_literal();
    std::string parse_id();
    std::string parse_id_list();

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
    std::map<std::string, int> regs_map;
    std::map<std::string, int> opcodes_map;
    Token matched;
    int idx;
};

#endif
