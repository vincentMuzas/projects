/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** CPU
*/

#include "CPU.hpp"

#include <iostream>

CPU::CPU()
{
    this->m_fnts[CPU::push] = &CPU::f_push;
    this->m_fnts[CPU::pop] = &CPU::f_pop;
    this->m_fnts[CPU::clear] = &CPU::f_clear;
    this->m_fnts[CPU::dup] = &CPU::f_dup;
    this->m_fnts[CPU::swap] = &CPU::f_swap;
    this->m_fnts[CPU::dump] = &CPU::f_dump;
    this->m_fnts[CPU::assert] = &CPU::f_assert;
    this->m_fnts[CPU::add] = &CPU::f_add;
    this->m_fnts[CPU::sub] = &CPU::f_sub;
    this->m_fnts[CPU::mul] = &CPU::f_mul;
    this->m_fnts[CPU::div] = &CPU::f_div;
    this->m_fnts[CPU::mod] = &CPU::f_mod;
    this->m_fnts[CPU::load] = &CPU::f_load;
    this->m_fnts[CPU::store] = &CPU::f_store;
    this->m_fnts[CPU::print] = &CPU::f_print;
    this->m_fnts[CPU::exit] = &CPU::f_exit;

        
    this->m_op_type[eOperandType::INT8] = "int8";
    this->m_op_type[eOperandType::INT16] = "int16";
    this->m_op_type[eOperandType::INT32] = "int32";
    this->m_op_type[eOperandType::FLOAT] = "float";
    this->m_op_type[eOperandType::DOUBLE] = "double";
    this->m_op_type[eOperandType::BIGDECIMAL] = "bigdecimal";

    for (int i = 0; i < 16; i++) {
        this->registers.push_back(nullptr);
    }
}

CPU::~CPU()
{
}

std::string CPU::call(fnts f, std::string &cmd)
{
    return ((this->*(m_fnts[f]))(cmd));
}

std::string CPU::get_arg(std::string &cmd)
{
    std::vector<std::string> result;
    std::string item;
    std::istringstream iss(cmd);
    while (std::getline(iss, item, ' '))
        result.push_back(item);
    return (result[1]);
}

std::string CPU::f_clear(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.clear();
    return ("");
}

std::string CPU::f_push(std::string &cmd)
{
    UNUSED(cmd);
    std::string loc = this->get_arg(cmd);
    std::string type, val;
    eOperandType t_new_operand;
    int ok = 0;
    for (auto const& [key, value] : this->m_op_type) {
        type = loc.substr(0, value.size());
        if (type == value) {
            t_new_operand = key;
            loc = loc.substr(value.size());
            ok = 1;
            break;
        }
    }
    if (ok == 1 && (loc[0] != '(' || loc[loc.size()] != ')')) {
        loc.erase(0, 1);
        loc.erase(loc.size() - 1);
    }
    if (!this->is_float_convertible(loc) || ok == 0)
        throw std::invalid_argument("bad input argument" + loc);
    this->ram.push(Factory::createOperand(t_new_operand, loc));
    return ("");
}
std::string CPU::f_pop(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.pop();
    return ("");
}
std::string CPU::f_dup(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.dup();
    return ("");
}
std::string CPU::f_swap(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.swap();
    return ("");
}
std::string CPU::f_dump(std::string &cmd)
{
    UNUSED(cmd);
    return (this->ram.dump());
}
std::string CPU::f_assert(std::string &cmd)
{
    std::string loc = this->get_arg(cmd);
    std::string type, val;
    eOperandType t_new_operand;
    int ok = 0;
    for (auto const& [key, value] : this->m_op_type) {
        type = loc.substr(0, value.size());
        if (type == value) {
            t_new_operand = key;
            loc = loc.substr(value.size());
            ok = 1;
            break;
        }
    }
    if (ok == 1 && (loc[0] != '(' || loc[loc.size()] != ')')) {
        loc.erase(0, 1);
        loc.erase(loc.size() - 1);
    }
    for (size_t i = 0; i < loc.size(); i++)
        if ((loc[i] < '0' || loc[i] > '9') || std::count(loc.begin(), loc.end(), '.') > 1)
            ok = 0;
    if (ok == 0)
        throw std::invalid_argument("bad input argument");
    this->ram.assert(Factory::createOperand(t_new_operand, loc));
    return ("");
}
std::string CPU::f_add(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.push(this->ram.store() + this->ram.store());
    return ("");
}
std::string CPU::f_sub(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.swap();
    this->ram.push(this->ram.store() - this->ram.store());
    return ("");
}
std::string CPU::f_mul(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.push(this->ram.store() * this->ram.store());
    return ("");
}
std::string CPU::f_div(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.swap();
    this->ram.push(this->ram.store() / this->ram.store());
    return ("");
}
std::string CPU::f_mod(std::string &cmd)
{
    UNUSED(cmd);
    this->ram.swap();
    this->ram.push(this->ram.store() % this->ram.store());
    return ("");
}
std::string CPU::f_load(std::string &cmd)
{
    int v = std::atoi(this->get_arg(cmd).c_str());
    if (v > 15 || v < 0)
        throw std::invalid_argument("bad index for load");
    this->ram.push(this->registers[v]);
    return ("");
}
std::string CPU::f_store(std::string &cmd)
{
    int v = std::atoi(this->get_arg(cmd).c_str());
    if (v > 15 || v < 0)
        throw std::invalid_argument("bad index for store");
    this->registers[v] = &this->ram.store();
    return ("");
}
std::string CPU::f_print(std::string &cmd)
{
    UNUSED(cmd);
    return (this->ram.print());
}
std::string CPU::f_exit(std::string &cmd)
{
    UNUSED(cmd);
    std::exit(0);
}

bool CPU::is_float_convertible(std::string &cmd)
{
    int dots = 0;
    int ok = 0;
    for (size_t i = 0; i < cmd.size(); i++) {
        if (cmd[i] >= '0' && cmd[i] <= '9') {
            ok ++;
        }
        else if (cmd[i] == '.')
            dots ++;
    }
    return (ok && (dots == 0 || dots == 1));
}