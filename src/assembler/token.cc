#include <sstream>
#include "token.h"

TokenKind Token::get_kind() {
    return kind;
}

void Token::set_kind(TokenKind value) {
    kind = value;
}

int Token::get_line() {
    return line;
}

void Token::set_line(int value) {
    line = value;
}

int Token::get_column() {
    return column;
}

void Token::set_column(int value) {
    column = value;
}

std::string Token::get_lexeme() {
    return lexeme;
}

void Token::set_lexeme(std::string value) {
    lexeme = value;
}


std::string Token::to_str() {
    std::stringstream ss;

    ss << "(" << kind << ", " << line << ", " << column << ", '" << lexeme << "')";
    return ss.str();
}
