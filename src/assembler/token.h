#ifndef TOKEN_H
#define TOKEN_H

#include <string>

typedef enum TokenKind {
    TK_ID,
    TK_ADD,
    TK_BEQ,
    TK_COMMA,
    TK_DOT
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

    private:
        TokenKind kind;
        int line;
        int column;
        std::string lexeme;
};

#endif
