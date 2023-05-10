#include <iostream>
#include "assembler.h"
#include "scanner.h"

int main(int argc, char** argv) {
    Scanner sc;

    std::vector<Token> tokens = sc.read(argv[1]);

    for (int i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i].to_str() << '\n';
    }

    return 0;
}
