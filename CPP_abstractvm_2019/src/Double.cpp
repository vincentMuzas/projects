#include <iostream>
#include <string>
#include "Factory.hpp"
#include "Double.hpp"

Double::Double(std::string value):_value(value), _type(eOperandType::DOUBLE)
{
//    std::cout << "Creation d'un objet Double qui a pour valeur " << _value << std::endl;
}

std::string Double::toString() const
{
    return _value;
}

eOperandType Double::getType() const
{
    return _type;
}