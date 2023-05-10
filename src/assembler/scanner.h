#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "token.h"

class Scanner {
    public:
        Scanner();

    public:
        std::vector<Token> read(std::string path);

    private:
        bool has_next();
        void get_token();
        void get_word();
        void get_punct();

        void create_token();
        void create_token(TokenKind kind);
        void advance();
        void start_token();
        void start_token(char ch);

        void get_punct_kind();
        TokenKind get_token_kind();

        bool is_alpha(char c);
        bool is_num(char c);
        bool is_alphanum(char c);
        bool is_punct(char c);
        bool is_whitespace(char c);

    private:
        std::vector<Token> tokens;
        std::map<std::string, TokenKind> tokens_map;
        std::ifstream file;
        char c;
        int line;
        int column;
        int token_line;
        int token_column;
        std::string lexeme;
};

#endif
