#include <iostream>
#include <string>
#include "Factory.hpp"
#include "Int16.hpp"

Int16::Int16(std::string value):_value(value), _type(eOperandType::INT16)
{
//    std::cout << "Creation d'un objet Int16 qui a pour valeur " << _value << std::endl;
}

std::string Int16::toString() const
{
    return _value;
}

eOperandType Int16::getType() const
{
    return _type;
}