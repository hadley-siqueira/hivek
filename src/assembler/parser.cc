#include <iostream>

#include "parser.h"
#include "scanner.h"
#include "module.h"
#include "byte_directive.h"

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
        } else {
            break;
        }
    }

    return mod;
}

Instruction* Parser::parse_directive() {
    Instruction* inst = nullptr;
    expect(TK_DOT);

    if (lookahead("byte")) {
        inst = parse_byte_directive();
    } else if (lookahead("string")) {
        parse_string_directive();
    }

    return inst;
}

Instruction* Parser::parse_byte_directive() {
    ByteDirective* dir = new ByteDirective();
    expect("byte");

    dir->add_value(parse_byte_literal());

    while (match(TK_COMMA)) {
        dir->add_value(parse_byte_literal());
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

