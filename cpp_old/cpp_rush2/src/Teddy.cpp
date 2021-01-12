/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	Teddy.cpp
*/

#include "../includes/Teddy.hpp"

Teddy::Teddy(const std::string &name) : Toy(name)
{
	this->c_type = Object::ObjectType::Teddy;
}

Teddy::~Teddy()
{
}

bool	Teddy::isTaken() const
{
	std::cout << WIERD_TEDDY_SCREAMING_LOUDLY << std::endl;
	return (this->Toy::isTaken());
}
