#include "Memory.hpp"
#include "Int8.hpp"

Memory::Memory()
{
}

Memory::~Memory()
{
}

std::string ioperandAsString(const IOperand &op)
{
    std::string nametext;
    nametext = typeid(op).name();
    nametext.append("(");
    nametext.append(op.toString());
    nametext.append(")");
    return nametext;
}

void Memory::push(const IOperand *operand)
{
    operation.push_back(operand);
}

void Memory::pop()
{
    if(!operation.empty()) {
        operation.pop_back();
    } else {
        throw std::invalid_argument("Stack empty, cannot removed last stack");
    }
}

void Memory::clear()
{
    operation.clear();
}

void Memory::dup()
{
    if (!operation.empty()) {
        push(this->operation.back());
    }
    else {
        throw std::invalid_argument("Stack is empty, cannot duplicate element");
    }
}

void Memory::swap()
{
    if (this->operation.size() < 2)
        throw std::invalid_argument("Stack is not big enough to swap elements");
    const IOperand *op1 = this->operation.back();
    this->operation.pop_back();
    const IOperand *op2 = this->operation.back();
    this->operation.pop_back();
    this->push(op1);
    this->push(op2);
}

std::string Memory::print() const
{
    if (this->operation.empty())
        throw std::invalid_argument("stack is empty, cannot print element");
    
    IOperand const *val = operation.back();
    if (val->getType() != eOperandType(INT8))
    {
 
        throw std::invalid_argument("Value at the top of the stack not INT8 object");

    }
    std::stringstream ret;
    ret << char(std::stoi(val->toString())); 
    //return (std::to_string(this->operation.back()->getType()));
    return (ret.str());
}

void Memory::assert(const IOperand *operand)
{
    if (this->operation.empty())
        throw std::invalid_argument("stack is empty, cannot assert");
    if (operation.back()->toString() != operand->toString() || operation.back()->getType() != operand->getType()){
        throw std::invalid_argument("Values doesn't match !");
    }
}

std::string Memory::dump()
{
    std::string dump_string;
    std::vector<const IOperand *> operation2;
    for (size_t i=0; i<operation.size(); i++) 
        operation2.push_back(operation[i]); 
    std::reverse(operation2.begin(),operation2.end());    // 9 8 7 6 5 4 3 2 1
    if (this->operation.empty())
        throw std::invalid_argument("stack is empty, cannot dump element");
    for(const auto &piece : operation2){
        dump_string += ("\n" + piece->toString());
    } 
    dump_string.erase(0,1);
    return (dump_string);
}

const IOperand& Memory::store()
{   
   if (this->operation.empty())
       throw std::invalid_argument("stack is empty, cannot store element");
    const IOperand* stored_item;
    stored_item = operation.back();
    operation.pop_back();
    return (*stored_item);
}