#include <iostream>
#include <string>
#include "Factory.hpp"
#include "BigDecimal.hpp"

BigDecimal::BigDecimal(std::string value):_value(value), _type(eOperandType::BIGDECIMAL)
{
//    std::cout << "Creation d'un objet BigDecimal qui a pour valeur " << _value << std::endl;
}

std::string BigDecimal::toString() const
{
    return _value;
}

eOperandType BigDecimal::getType() const
{
    return _type;
}