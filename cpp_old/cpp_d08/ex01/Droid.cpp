/*
** EPITECH PROJECT, 2018
** Droid.cpp
** File description:
**
*/

#include "Droid.hpp"

Droid::Droid(std::string serial): Id(serial), Attack(25), Thoughness(15),
				       Energy(50)
{
	Status = new (std::string)("Standing by");
	std::cout << "Droid '" << serial << "' Activated" << std::endl;
}

Droid &Droid::operator=(const Droid &old)
{
	this->Id = old.Id;
	this->setStatus(new std::string(*old.Status));
	this->Energy = old.Energy;
	return *this;
}

bool Droid::operator==(const Droid &rop)
{
	return Status == rop.Status;
}

bool Droid::operator!=(const Droid &rop)
{
	return !(this == &rop);
}

Droid &Droid::operator<<(size_t &value)
{
	while (value > 0 && this->Energy < 100) {
		value -= 1;
		this->Energy += 1;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &s, Droid &droid)
{
	s << "Droid '" << droid.getId() << "', " << droid.getStatus()
	  << ", " << droid.getEnergy();
	return s;
}

std::string Droid::getId() const
{
	return this->Id;
}

std::string Droid::getStatus() const
{
	return *Status;
}

size_t Droid::getEnergy() const
{
	return this->Energy;
}

size_t Droid::getAttack() const
{
	return this->Attack;
}

size_t Droid::getThoughness() const
{
	return this->Thoughness;
}

void Droid::setId(const std::string to_set)
{
	this->Id = to_set;
}

void Droid::setStatus(std::string *to_set)
{
	this->Status = to_set;
}

void Droid::setEnergy(const size_t to_set)
{
	if (to_set <= 100)
		this->Energy = to_set;
}
