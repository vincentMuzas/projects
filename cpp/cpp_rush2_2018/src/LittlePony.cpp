/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	LittlePony.cpp
*/

#include "../includes/LittlePony.hpp"

LittlePony::LittlePony(const std::string &name) : Toy(name)
{
	this->c_type = Object::ObjectType::LittlePony;
}

LittlePony::~LittlePony()
{
}

bool	LittlePony::isTaken() const
{
	std::cout << LITTLE_PONY_S_FRIENDLY_SCREAM << std::endl;
	return (this->Toy::isTaken());
}
