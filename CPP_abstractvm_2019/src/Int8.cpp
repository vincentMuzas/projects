#include "Int8.hpp"
#include <iostream>
#include <string>
#include "Factory.hpp"

Int8::Int8(std::string value):_value(value), _type(eOperandType::INT8)
{
//    std::cout << "Creation d'un objet Int8 qui a pour valeur " << _value << std::endl;
}

std::string Int8::toString() const
{
    return _value;
}

eOperandType Int8::getType() const
{
    return _type;
}