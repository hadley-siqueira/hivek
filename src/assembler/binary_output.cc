#include <fstream>
#include "binary_output.h"

void BinaryOutput::write(std::string path) {
    std::ofstream file(path);

    for (int i = 0; i < bytes.size(); ++i) {
        file << bytes[i];
    }

    file.close();
}

void BinaryOutput::append(uint8_t value) {
    bytes.push_back(value);
}
