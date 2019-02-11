/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name(name),
							  title(title)
{
	std::cout << this->name << ", " << this->title
		  << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", is dead. "
		  << "Consequences will never be the same!" << std::endl;
}

std::ostream &operator<<(std::ostream &lop, Sorcerer &rop)
{
	lop << "I am " << rop.name << ", " << rop.title
	  << ", and I like ponies!" << std::endl;
	return lop;
}

void Sorcerer::polymorph(const Victim &victim) const
{
	victim.getPolymorphed();
}
