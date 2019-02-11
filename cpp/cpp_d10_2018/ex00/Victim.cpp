/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Victim
*/

#include "Victim.hpp"
#include "Sorcerer.hpp"

Victim::Victim(std::string _name) : name(_name)
{
	std::cout << "Some random victim called " << this->name
		  << " just popped!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name
		  << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream &lop, Victim &rop)
{
	lop << "I'm " << rop.name << " and i like otters!" << std::endl;
	return lop;
}

void Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep!"
		  << std::endl;
}
