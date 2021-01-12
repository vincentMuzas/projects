/*
** EPITECH PROJECT, 2018
** CPP_Rush2
** File description:
** A Toy to wrap
*/

#include "../includes/Toy.hpp"

Toy::Toy(const std::string &name) : Object(name)
{
	this->c_type = Object::ObjectType::Toy;
}

Toy::~Toy()
{
}
