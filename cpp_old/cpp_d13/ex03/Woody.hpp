/*
** EPITECH PROJECT, 2018
** Woody.hpp
** File description:
** 
*/

#pragma once

#include "Toy.hpp"

class Woody : public Toy
{
public:
	Woody(std::string name, std::string file = "woody.txt");
	~Woody();
	bool speak(std::string say) override;
};
