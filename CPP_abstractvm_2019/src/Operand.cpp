#include "Operand.hpp"
#include "Factory.hpp"

IOperand* Operand::operator+(const IOperand &rhs) const
{
    eOperandType resultType;
    std::string result_val;

    (this->getType() >= rhs.getType()) ? resultType = this->getType() : resultType = rhs.getType();
    if (resultType <3) {
        result_val = std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString()));
    } else if (resultType == FLOAT) {
        result_val = std::to_string(std::stof(this->toString()) + std::stof(rhs.toString()));    
    } else {
        result_val = std::to_string(std::stod(this->toString()) + std::stod(rhs.toString()));  
    }  
    IOperand* result = Factory::createOperand(resultType, result_val);
    return result;
}

IOperand* Operand::operator-(const IOperand &rhs) const 
{
    eOperandType resultType;
    std::string result_val;
    (this->getType() >= rhs.getType()) ? resultType = this->getType() : resultType = rhs.getType();
    if (resultType <3) {
        result_val = std::to_string(std::stoi(this->toString()) - std::stoi(rhs.toString()));
    } else if (resultType == FLOAT) {
        result_val = std::to_string(std::stof(this->toString()) - std::stof(rhs.toString()));    
    } else {
        result_val = std::to_string(std::stod(this->toString()) - std::stod(rhs.toString()));  
    }  
    IOperand* result = Factory::createOperand(resultType, result_val);
    return result;
} 

IOperand* Operand::operator*(const IOperand &rhs) const
{
    eOperandType resultType;
    std::string result_val;
    (this->getType() >= rhs.getType()) ? resultType = this->getType() : resultType = rhs.getType();
    if (resultType <3) {
        result_val = std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString()));
    } else if (resultType == FLOAT) {
        result_val = std::to_string(std::stof(this->toString()) * std::stof(rhs.toString()));    
    } else {
        result_val = std::to_string(std::stod(this->toString()) * std::stod(rhs.toString()));  
    }  
    IOperand* result = Factory::createOperand(resultType, result_val);
    return result;
}

IOperand* Operand::operator/(const IOperand &rhs) const
{
    eOperandType resultType;
    std::string result_val;

    (this->getType() >= rhs.getType()) ? resultType = this->getType() : resultType = rhs.getType();
    if (rhs.toString() == "0" || rhs.toString()== "")
        throw std::invalid_argument("Error: division by 0");
    if (resultType <3) {
        result_val = std::to_string(std::stoi(this->toString()) / std::stoi(rhs.toString()));
    } else if (resultType == FLOAT) {
        result_val = std::to_string(std::stof(this->toString()) / std::stof(rhs.toString()));    
    } else {
        result_val = std::to_string(std::stod(this->toString()) / std::stod(rhs.toString()));  
    }  
    IOperand* result = Factory::createOperand(resultType, result_val);
    return result;
}

IOperand* Operand::operator%(const IOperand &rhs) const
{
    eOperandType resultType;
    std::string result_val;
    (this->getType() >= rhs.getType()) ? resultType = this->getType() : resultType = rhs.getType();
    if (resultType <3) {
        result_val = std::to_string(std::stoi(this->toString()) % std::stoi(rhs.toString()));  
    } else {
        throw std::invalid_argument("modulo needs integer value");
    }  
    IOperand* result = Factory::createOperand(resultType, result_val);
    return result;
}