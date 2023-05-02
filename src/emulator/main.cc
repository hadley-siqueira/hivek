#include "emulator.h"

int main(int argc, char* argv[]) {
    Emulator emulator;

    emulator.read_bin(argv[1]);
    emulator.dump_memory();

    return 0;
}
