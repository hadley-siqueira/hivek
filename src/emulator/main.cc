#include <iostream>
#include "emulator.h"

int main(int argc, char* argv[]) {
    Emulator emulator;

    emulator.read_bin(argv[1]);
    emulator.dump_memory();

    for (int i = 0; i < 50; ++i) {
        emulator.tick();
    }

    emulator.dump_registers();
    emulator.dump_memory();

    return 0;
}
