/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Peon
*/

#include "Peon.hpp"
#include "Sorcerer.hpp"

Peon::Peon(std::string _name) : Victim(_name)
{
	this->name = _name;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony!"
		  << std::endl;
}

