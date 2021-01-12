/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#include "../includes/Wrap.hpp"

Wrap::Wrap(const std::string & title): Object(title), c_open(true)
{
        this->c_objIn = nullptr;
        this->c_type =  Object::ObjectType::Wrap;}

Wrap::~Wrap()
{
	if (this->c_objIn != nullptr) {
		delete this->c_objIn;
	}}

bool Wrap::isOpen()
{
        return (this->c_open);}

void Wrap::setIsOpen(bool open)
{
        this-> c_open = open;
}

void Wrap::placeObj(Object *obj)
{
        this->c_objIn = obj;
}

Object *Wrap::extractObj()
{
        Object *extractPtr = this->c_objIn;

        this->c_objIn = nullptr;
        return (extractPtr);
}

Object *Wrap::getObj()
{
        return (this->c_objIn);
}

bool Wrap::isEmpty()
{
        if (this->c_objIn == nullptr)
                return (true);
        return (false);
}
