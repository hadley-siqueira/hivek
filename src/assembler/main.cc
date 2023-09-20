#include <iostream>
#include "assembler.h"
#include "scanner.h"
#include "parser.h"

void test_scanner(int argc, char** argv) {
    Scanner sc;

    std::vector<Token> tokens = sc.read(argv[1]);

    for (int i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i].to_str() << '\n';
    }
}

void test_parser(int argc, char** argv) {
    Parser p;

    p.parse(argv[1]);
}

int main(int argc, char** argv) {

    test_parser(argc, argv);
    Assembler as;

    as.read(argv[1]);

    as.generate_output("out.bin");
    return 0;
}
