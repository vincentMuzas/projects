#pragma once

#include "IOperand.hpp"
#include "Operand.hpp"
#include <string>

class Float : public Operand
{
public:
    Float(std::string value);
    virtual std::string toString() const; // string that represents the instance
    virtual eOperandType getType() const; // returns the type of instance

protected:
    std::string _value;
    eOperandType _type;
};