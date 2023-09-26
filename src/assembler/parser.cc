#include <iostream>
#include <sstream>

#include "parser.h"
#include "scanner.h"
#include "module.h"
#include "data_directive.h"
#include "label.h"

Module* Parser::parse(std::string path) {
    Scanner sc;

    idx = 0;
    tokens = sc.read(path);

    for (int i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i].to_str() << '\n';
    }

    return parse_module();
}

Module* Parser::parse_module() {
    Module* mod = new Module();

    while (true) {
        if (lookahead(TK_DOT)) {
            mod->add_to_section(parse_directive());
        } else if (lookahead(TK_ID)) {
            mod->add_to_section(parse_label_or_instruction());
        } else {
            break;
        }
    }

    return mod;
}

Command* Parser::parse_directive() {
    Command* inst = nullptr;
    expect(TK_DOT);

    if (lookahead("byte")) {
        inst = parse_byte_directive();
    } else if (lookahead("int")) {
        inst = parse_int_directive();
    } else if (lookahead("string")) {
        parse_string_directive();
    }

    return inst;
}

Command* Parser::parse_byte_directive() {
    DataDirective* dir = new DataDirective(CMD_BYTE_DIRECTIVE);
    expect("byte");

    dir->add_value(parse_byte_literal());

    while (match(TK_COMMA)) {
        dir->add_value(parse_byte_literal());
    }

    return dir;
}

Command* Parser::parse_int_directive() {
    DataDirective* dir = new DataDirective(CMD_INT_DIRECTIVE);
    expect("int");

    dir->add_value(parse_int_literal());

    while (match(TK_COMMA)) {
        dir->add_value(parse_int_literal());
    }

    return dir;
}

void Parser::parse_string_directive() {
    expect("string");
    expect(TK_STRING);
}

Token Parser::parse_byte_literal() {
    expect(TK_NUMBER);
    return matched;
}

Token Parser::parse_int_literal() {
    expect(TK_NUMBER);
    return matched;
}

Command* Parser::parse_label_or_instruction() {
    std::string id = parse_id();

    if (match(TK_COLON)) {
        return new Label(id);
    } 

    return parse_instruction(id);
}

Command* Parser::parse_instruction(std::string op) {
    if (op == "add") {
        return parse_instruction_reg_reg_reg("add");
    }

    return nullptr;
}

Command* parse_instruction_reg_reg_reg(std::string op) {
    return nullptr;
}

std::string Parser::parse_id() {
    std::stringstream id;
    expect(TK_ID);
    id << matched.get_lexeme();

    while (match(TK_DOT)) {
        expect(TK_ID);
        id << '.' << matched.get_lexeme();
    }

    if (match(TK_HASH)) {
        expect(TK_ID);
        id << "#" << matched.get_lexeme();
    }

    if (match(TK_LT)) {
        id << '<' << parse_id_list();
        expect(TK_GT);
        id << '>';
    }

    if (match(TK_LPAREN)) {
        id << '(' << parse_id_list();
        expect(TK_RPAREN);
        id << ')';
    }

    return id.str();
}

std::string Parser::parse_id_list() {
    std::stringstream l;

    l << parse_id();

    while (match(TK_COMMA)) {
        l << ", " << parse_id();
    }

    return l.str();
}

void Parser::expect(int kind) {
    if (match(kind)) {
        return;
    }

    //log_error_and_exit(error_unexpected_token(path, tokens[idx]));
    std::cout << "expect error\n";
    exit(0);
}

void Parser::expect(std::string lexeme) {
    if (match(lexeme)) {
        return;
    }

    //log_error_and_exit(error_unexpected_token(path, tokens[idx]));
    std::cout << "expect error\n";
    exit(0);
}

bool Parser::match(int kind) {
    if (lookahead(kind)) {
        matched = tokens[idx];
        advance();
        return true;
    }

    return false;
}

bool Parser::match(std::string lexeme) {
    if (lookahead(lexeme)) {
        matched = tokens[idx];
        advance();
        return true;
    }

    return false;
}

bool Parser::lookahead(int kind) {
    return tokens[idx].get_kind() == kind;
}

bool Parser::lookahead(std::string lexeme) {
    return tokens[idx].get_lexeme() == lexeme;
}

void Parser::advance() {
    if (idx < tokens.size()) {
        ++idx;
    }
}

