/*
** EPITECH PROJECT, 2019
** cpp_d08_2018
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial): Id(serial),Energy(50),Attack(25),Toughness(15)
{
	this->setStatus(new std::string("Standing by"));
	std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid &old) : Id(old.getId()),Energy(50),Attack(25), Toughness(15)
{
	this->setStatus(new std::string("Standing by"));
	std::cout << "Droid '"<< Id <<"' Activated, Memory Dumped" << std::endl;
}

bool Droid::operator==(const Droid &rop)
{
	if (Status->compare(*rop.Status)) {
		return (true);
	}
	return (false);
}

bool Droid::operator!=(const Droid &rop)
{
	return (!(*this == rop));
}

Droid::~Droid()
{
	std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Droid &src)
{
	s << "Droid '" << src.getId() << "', " << *src.getStatus()<< ", " << src.getEnergy();
	return (s);
}

Droid &Droid::operator=(const Droid &rop)
{
	this->setId(rop.getId());
	this->setEnergy(rop.getEnergy());
	this->setStatus(rop.getStatus());
	return (*this);
}


Droid &operator<<(Droid &lop, size_t &rop)
{
	while (lop.getEnergy() < 100 && rop > 0) {
		rop --;
		lop.setEnergy(lop.getEnergy() + 1);
	}
	return (lop);
}