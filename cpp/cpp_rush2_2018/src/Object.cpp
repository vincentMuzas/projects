/*
** EPITECH PROJECT, 2018
** object.cpp
** File description:
**
*/

#include "../includes/Object.hpp"

Object::Object(const std::string &name) : c_type(ObjectType::None),
					p_title(name)
{
	this->p_taken = false;
	this->p_wrapped = false;
}

Object::~Object()
{
}

bool	Object::is(const ObjectType type) const
{
	return ((this->c_type & type) == type);
}

bool	Object::operator==(ObjectType type) const
{
	return (this->c_type == type);
}

bool	Object::operator!=(ObjectType type) const
{
	return (this->c_type != type);
}

std::string	Object::getTypeName() const
{
	switch (this->c_type) {
	case ObjectType::None:
		return "Object";

	case ObjectType::Toy:
		return "Toy";

	case ObjectType::Wrap:
		return "Wrap";

	case ObjectType::Teddy:
		return "Teddy";

	case ObjectType::LittlePony:
		return "LittlePony";

	case ObjectType::Box:
		return "Box";

	case ObjectType::GiftPaper:
		return "GiftPaper";

	default:
		return "Unknown";
	}
}

bool	Object::isTaken() const
{
	return (this->p_taken);
}

void	Object::setWrapped(bool status)
{
	this->p_wrapped = status;
}

void Object::setTitle(const std::string &name)
{
	this->p_title = name;
}
