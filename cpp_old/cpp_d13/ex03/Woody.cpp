/*
** EPITECH PROJECT, 2018
** Woody.cpp
** File description:
** 
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string file) :
	Toy::Toy(Toy::WOODY, name, file)
{
}

Woody::~Woody()
{
}

bool Woody::speak(std::string say)
{
	std::cout << "WOODY: " << this->getName() << " \""
		  << say << "\"" << std::endl;
	return true;
}
