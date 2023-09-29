#ifndef TOKEN_H
#define TOKEN_H

#include <string>

typedef enum TokenKind {
    TK_ID,
    TK_NUMBER,
    TK_STRING,
    TK_COMMA,
    TK_DOT,
    TK_SEMICOLON,
    TK_COLON,
    TK_MODULO,
    TK_HASH,
    TK_LT,
    TK_GT,
    TK_LPAREN,
    TK_RPAREN,
    TK_MINUS,

    TK_EOF
} TokenKind;

class Token {
    public:
        TokenKind get_kind();
        void set_kind(TokenKind value);

        int get_line();
        void set_line(int value);

        int get_column();
        void set_column(int value);

        std::string get_lexeme();
        void set_lexeme(std::string value);

        std::string to_str();

    private:
        TokenKind kind;
        int line;
        int column;
        std::string lexeme;
};

#endif
