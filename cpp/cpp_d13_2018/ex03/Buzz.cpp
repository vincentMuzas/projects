/*
** EPITECH PROJECT, 2018
** buzz.cpp
** File description:
** 
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string file) : Toy::Toy(Toy::BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(std::string say)
{
	std::cout << "BUZZ: " << this->getName() << " \""
		  << say << "\"" << std::endl;
	return true;
}

bool Buzz::speak_es(std::string say)
{
	std::cout << "BUZZ: " << this->getName() << " senorita \""
		  << say << "\" senorita" << std::endl;
	return true;
}
