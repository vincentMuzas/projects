/*
** EPITECH PROJECT, 2018
** Buzz.hpp
** File description:
** 
*/

#pragma once

#include "Toy.hpp"

class Buzz : public Toy
{
public:
	Buzz(std::string name, std::string file = "buzz.txt");
	~Buzz();
	bool speak(std::string say) override;
	bool speak_es(std::string say) override;
};
