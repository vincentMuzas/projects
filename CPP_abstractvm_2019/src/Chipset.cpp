/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** Chipset
*/

#include "Chipset.hpp"

Chipset::Chipset()
{
    this->functions[CPU::push] = "push ";
    this->functions[CPU::pop] = "pop ";
    this->functions[CPU::clear] = "clear ";
    this->functions[CPU::dup] = "dup ";
    this->functions[CPU::swap] = "swap ";
    this->functions[CPU::dump] = "dump ";
    this->functions[CPU::assert] = "assert ";
    this->functions[CPU::add] = "add ";
    this->functions[CPU::sub] = "sub ";
    this->functions[CPU::mul] = "mul ";
    this->functions[CPU::div] = "div ";
    this->functions[CPU::mod] = "mod ";
    this->functions[CPU::load] = "load ";
    this->functions[CPU::store] = "store ";
    this->functions[CPU::print] = "print ";
    this->functions[CPU::exit] = "exit ";
}

Chipset::~Chipset()
{
}

void Chipset::run()
{
}

std::string Chipset::communicate(std::string &str)
{
    str.push_back(' ');
    for (auto const& [key, value] : this->functions) {
        if (str.substr(0, value.length()) == value) {
            return (cpu.call(key, str));
        }
    }
    return ("no match for: " + str);
}