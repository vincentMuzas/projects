#include <iostream>
#include <string>
#include "Factory.hpp"
#include "Int32.hpp"

Int32::Int32(std::string value):_value(value), _type(eOperandType::INT32)
{
//    std::cout << "Creation d'un objet Int32 qui a pour valeur " << _value << std::endl;
}

std::string Int32::toString() const
{
    return _value;
}

eOperandType Int32::getType() const
{
    return _type;
}