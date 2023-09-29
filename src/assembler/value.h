#ifndef VALUE_H
#define VALUE_H

#include <string>

enum ValueKind {
    VAL_REG,
    VAL_ID,
    VAL_NUMBER
};

class Value {
public:
    Value(int kind);
    Value(int kind, std::string value);

public:
    void set_value(std::string value);
    int to_int();

private:
    int kind;
    std::string value;
};

#endif
