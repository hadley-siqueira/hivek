#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "token.h"

class Parser {
public:
    void parse(std::string path);

private:
    void parse_module();

    void parse_directive();
    void parse_byte_directive();
    void parse_string_directive();

    void parse_byte_literal();

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
    Token matched;
    int idx;
};

/*    void parse() {
        switch (token.get_kind()) {
        case TK_ADD:
            
        }
    }

    // add %0, %1, %2
    void parse_add() {
        expect(TK_ADD);

        int rc = parse_reg();
        expect(TK_COMMA);

        int ra = parse_reg();
        expect(TK_COMMA);

        int rb = parse_reg();
    }

    void parse_reg() {

        return 
    }*/

#endif
