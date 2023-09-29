#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "command.h"

class Label : public Command {
public:
    Label(std::string value);

public:
    void set_offset(int value);
    std::string get_value();

private:
    std::string value;
    int offset;
};

#endif
