#pragma once

#include "IOperand.hpp"

#define UNUSED(expr) do { (void)(expr); } while (0)

class Factory
{
public:
    static IOperand* createOperand(eOperandType type, const std::string &value );
private:
    static IOperand* createInt8(const std::string &value);
    static IOperand* createInt16(const std::string &value);
    static IOperand* createInt32(const std::string &value);
    static IOperand* createFloat(const std::string &value);
    static IOperand* createDouble(const std::string &value);
    static IOperand* createBigDecimal(const std::string &value);
};