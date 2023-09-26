#ifndef LABEL_H
#define LABEL_H

#include "command.h"

class Label : public Command {
public:
    Label(std::string value);

private:
    std::string value;
};

#endif
