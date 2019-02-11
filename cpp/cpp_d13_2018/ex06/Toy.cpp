/*
** EPITECH PROJECT, 2018
** Tou.cpp
** File description:
** 
*/

#include "Toy.hpp"

Toy::Toy() : _type(Toy::BASIC_TOY), _Name("toy"), _ascii("")
{
}

Toy::Toy(int type, std::string Name, std::string fileName) :
	_type(type), _Name(Name)
{
	Picture p(fileName.c_str());

	if (p.data == "" || p.data == "ERROR") {
		this->lastErr.type = Toy::Error::PICTURE;
	}
	_ascii = p.data;
}

int Toy::getType() const
{
	return this->_type;
}

std::string Toy::getName() const
{
	return this->_Name;
}

std::string Toy::getAscii() const
{
	return this->_ascii;
}

bool Toy::setName(std::string Name)
{
	this->_Name = Name;
	return true;
}

bool Toy::setAscii(std::string fileName)
{
	Picture p(fileName.c_str());

	if (p.data == "" || p.data == "ERROR") {
		this->lastErr.type = Toy::Error::PICTURE;
		return false;
	}
	this->_ascii = p.data;
	return true;
}

bool Toy::speak(std::string say)
{
	std::cout << this->getName() << " \"" << say << "\"" << std::endl;
	return (true);
}

bool Toy::speak_es(std::string say)
{
	if (this->_type == Toy::BUZZ) {
		std::cout << "BUZZ: " << this->getName() << " senorita \""
			  << say << "\" senorita" << std::endl;
		return true;
	}
	this->lastErr.type = Toy::Error::SPEAK;
	return false;
}

std::ostream &operator<<(std::ostream &lop, Toy &rop)
{
	lop << rop.getName() << std::endl << rop.getAscii() << std::endl;
	return lop;
}

Toy Toy::operator<<(std::string rop)
{
	this->_ascii = rop;
	return *this;
}

Toy::Error Toy::getLastError()
{
	return this->lastErr;
}


Toy::Error::Error() : type(Toy::Error::UNKNOWN)
{
}

std::string Toy::Error::what()
{
	switch (this->type) {
	case Toy::Error::PICTURE:
		return "bad new illustration";
	case Toy::Error::SPEAK:
		return "wrong mode";
	}
	return "";
}

std::string Toy::Error::where()
{
	switch (this->type) {
	case Toy::Error::PICTURE:
		return "setAscii";
	case Toy::Error::SPEAK:
		return "speak_es";
	}
	return "";
}
