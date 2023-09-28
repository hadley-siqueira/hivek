#ifndef BINARY_OUTPUT_H
#define BINARY_OUTPUT_H

#include <cstdint>
#include <vector>
#include <string>

class BinaryOutput {
public:
    void write(std::string path);
    void append(uint8_t value);
    void append32(uint32_t value);
    int size();

private:
    std::vector<uint8_t> bytes;
};

#endif
