#include "scanner.h"

Scanner::Scanner() {
    line = 1;
    column = 1;

    tokens_map["add"] = TK_ADD;
    tokens_map["beq"] = TK_BEQ;
}

std::vector<Token> Scanner::read(std::string path) {
    file.open(path);

    while (has_next()) {
        get_token();
    }

    return tokens;
}

bool Scanner::has_next() {
    return file.good();
}

void Scanner::get_token() {
    if (is_alpha(c)) {
        get_word();
    } else if (is_num(c)) {

    } else if (is_punct(c)) {

    } else if (c == '"') {

    }
}

void Scanner::get_word() {
    TokenKind kind = TK_ID;

    start_token();

    while (is_alphanum(c)) {
        advance();
    }

    kind = get_token_kind();


    create_token(kind);
}

void Scanner::create_token(TokenKind kind) {
    Token token;

    token.set_kind(kind);
    token.set_line(line);
    token.set_column(column);
    token.set_lexeme(lexeme);

    lexeme = "";

    tokens.push_back(token);
}

void Scanner::advance() {
    file.get(c);

    if (c != '\n') {
        ++column;
        lexeme += c;
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
    return c == '.' || c == ',' || c == '%';
}

