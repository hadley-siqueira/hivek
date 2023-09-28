#include <fstream>
#include "binary_output.h"

void BinaryOutput::write(std::string path) {
    std::ofstream file(path);

    for (int i = 0; i < bytes.size(); ++i) {
        file << bytes[i];
    }

    file.close();
}

int BinaryOutput::size() {
    return bytes.size();
}

void BinaryOutput::append(uint8_t value) {
    bytes.push_back(value);
}

void BinaryOutput::append32(uint32_t value) {
    append((value >> 24) & 0xff);
    append((value >> 16) & 0xff);
    append((value >> 8) & 0xff);
    append(value & 0xff);
}
