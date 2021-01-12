#include <iostream>
#include <sstream>
#include "Factory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "BigDecimal.hpp"

IOperand* Factory::createOperand(eOperandType type, const std::string &value )
{
    switch(type)
        {
            case eOperandType::INT8:
            {
                return Factory::createInt8(value);
            }
            case eOperandType::INT16:
            {
                return Factory::createInt16(value);
            }
            case eOperandType::INT32:
            {
                return Factory::createInt32(value);
            }
            case eOperandType::FLOAT:
            {
                return Factory::createFloat(value);
            }
            case eOperandType::DOUBLE:
            {
                return Factory::createDouble(value);
            }
            case eOperandType::BIGDECIMAL:
            {
                return Factory::createBigDecimal(value);
            }
        }
    throw std::invalid_argument("cannot create new operand");
}

IOperand* Factory::createInt8(const std::string &value)
{
    return new Int8(value);
}

IOperand* Factory::createInt16(const std::string &value)
{
    return new Int16(value);
}

IOperand* Factory::createInt32(const std::string &value)
{
    return new Int32(value);
}

IOperand* Factory::createFloat(const std::string &value)
{
    return new Float(value);
}

IOperand* Factory::createDouble(const std::string &value)
{
    return new Double(value);
}

IOperand* Factory::createBigDecimal(const std::string &value)
{
    return new BigDecimal(value);
}