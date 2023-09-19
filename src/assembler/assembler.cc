#include <sstream>
#include <fstream>
#include "assembler.h"
#include "parser.h"
#include "binary_output.h"

void Assembler::read(std::string path) {
    Parser p;

    mod = p.parse(path);
}

void Assembler::generate_output(std::string path) {
    BinaryOutput out;

    out.write("/tmp/test.bin");
}
