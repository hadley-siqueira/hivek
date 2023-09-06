#include <iostream>

#include "parser.h"
#include "scanner.h"

void Parser::parse(std::string path) {
    Scanner sc;

    idx = 0;
    tokens = sc.read(path);

    for (int i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i].to_str() << '\n';
    }
}

void Parser::parse_module() {
    while (true) {
        if (lookahead(TK_DOT)) {
            parse_directive();
        }
    }
}

void Parser::parse_directive() {
    expect(TK_DOT);

    if (lookahead("byte")) {
        parse_byte_directive();
    } else if (lookahead("string")) {
        parse_string_directive();
    }
}

void Parser::parse_byte_directive() {
    expect("byte");

    parse_byte_literal();

    while (match(TK_COMMA)) {
        parse_byte_literal();
    }
}

void Parser::parse_string_directive() {
    expect("string");
    expect(TK_STRING);
}

void Parser::parse_byte_literal() {

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

