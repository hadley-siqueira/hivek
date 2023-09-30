#include "command.h"

void Command::write_to(BinaryOutput* value) {

}

int Command::get_kind() {
    return kind;
}

int Command::get_size() {
    return 0;
}

int Command::get_offset() {
    return offset;
}

void Command::set_offset(int offset) {
    this->offset = offset;
}
