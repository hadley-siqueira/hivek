#include <iostream>
#include "scanner.h"

Scanner::Scanner() {
    line = 1;
    column = 1;

    tokens_map[","] = TK_COMMA;
    tokens_map["."] = TK_DOT;
    tokens_map[":"] = TK_COLON;
    tokens_map[";"] = TK_SEMICOLON;
    tokens_map["%"] = TK_MODULO;
    tokens_map[""] = TK_MODULO;

    tokens_map["EOF"] = TK_EOF;
}

std::vector<Token> Scanner::read(std::string path) {
    file.open(path);

    advance();

    while (has_next()) {
        get_token();
    }

    start_token();
    create_token(TK_EOF);
    return tokens;
}

bool Scanner::has_next() {
    return file.good();
}

void Scanner::get_token() {
    if (is_alpha(c)) {
        get_word();
    } else if (is_num(c)) {
        get_number();
    } else if (is_punct(c)) {
        get_punct();
    } else if (c == '"') {

    } else if (is_whitespace(c)) {
        advance();
    }
}

void Scanner::get_word() {
    start_token();

    while (is_alphanum(c)) {
        advance();
    }

    create_token();
}

void Scanner::get_punct() {
    start_token();

    while (is_punct(c)) {
        advance();
    }

    get_punct_kind();
    create_token();
}

void Scanner::get_number() {
    start_token();

    while (is_num(c)) {
        advance();
    }

    create_token(TK_NUMBER);
}


void Scanner::create_token() {
    Token token;

    token.set_kind(get_token_kind());
    token.set_line(line);
    token.set_column(column);
    token.set_lexeme(lexeme);

    tokens.push_back(token);
}

void Scanner::create_token(TokenKind kind) {
    Token token;

    token.set_kind(kind);
    token.set_line(line);
    token.set_column(column);
    token.set_lexeme(lexeme);

    tokens.push_back(token);
}

void Scanner::advance() {
    lexeme += c;
    file.get(c);

    if (c != '\n') {
        ++column;
    } else {
        line += 1;
        column = 1;
    }
}

void Scanner::start_token() {
    token_line = line;
    token_column = column;
    lexeme = "";
}

void Scanner::start_token(char ch) {
    start_token();
    lexeme += ch;
}

void Scanner::get_punct_kind() {
    while (tokens_map.count(lexeme) == 0 && lexeme.size() > 0) {
        lexeme.pop_back();
    }
}

TokenKind Scanner::get_token_kind() {
    TokenKind kind = TK_ID;

    if (tokens_map.count(lexeme) > 0) {
        kind = tokens_map[lexeme];
    }

    return kind;
}

bool Scanner::is_alpha(char c) {
    return c >= 'a' && c <= 'z' || c>= 'A' && c <= 'Z' || c == '_';
}

bool Scanner::is_num(char c) {
    return c >= '0' && c <= '9';
}

bool Scanner::is_alphanum(char c) {
    return is_alpha(c) || is_num(c);
}

bool Scanner::is_punct(char c) {
    return c == ',' || c == '%' || c == ':' || c == ';' || c == '.';
}

bool Scanner::is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}
