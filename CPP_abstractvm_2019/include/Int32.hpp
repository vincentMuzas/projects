#pragma once

#include "IOperand.hpp"
#include "Operand.hpp"
#include <string>

class Int32 : public Operand
{
public:
    Int32(std::string value);
    virtual std::string toString() const; // string that represents the instance
    virtual eOperandType getType() const; // returns the type of instance

protected:
    std::string _value;
    eOperandType _type;
};