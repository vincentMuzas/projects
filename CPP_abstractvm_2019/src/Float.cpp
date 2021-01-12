#include <iostream>
#include <string>
#include "Factory.hpp"
#include "Float.hpp"

Float::Float(std::string value):_value(value), _type(eOperandType::FLOAT)
{
//    std::cout << "Creation d'un objet Float qui a pour valeur " << _value << std::endl;
}

std::string Float::toString() const
{
    return _value;
}

eOperandType Float::getType() const
{
    return _type;
}