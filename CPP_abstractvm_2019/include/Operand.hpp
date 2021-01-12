#pragma once

#include "IOperand.hpp"

class Operand : public IOperand
{
public:
    virtual IOperand* operator+(const IOperand &rhs) const; // sum
    virtual IOperand* operator-(const IOperand &rhs) const; // difference
    virtual IOperand* operator*(const IOperand &rhs) const; // product
    virtual IOperand* operator/(const IOperand &rhs) const; // quotient
    virtual IOperand* operator%(const IOperand &rhs) const; // modulo
private:
    std::string _value;
    eOperandType _type;
};
