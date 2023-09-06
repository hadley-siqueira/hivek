#include "emulator.h"

int main(int argc, char* argv[]) {
    Emulator emulator;

    emulator.read_txt(argv[1]);
    emulator.dump_memory();

    emulator.tick();
    emulator.tick();
    emulator.tick();
    emulator.dump_registers();

    return 0;
}
