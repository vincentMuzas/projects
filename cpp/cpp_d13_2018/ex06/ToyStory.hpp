/*
** EPITECH PROJECT, 2018
** ToyStory.hpp
** File description:
** 
*/

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Toy.hpp"

class ToyStory {
public:
	class tellMeAStory {
	public:
		tellMeAStory(std::string file,
			     Toy toy1, bool (Toy::*func1)(std::string),
			     Toy toy2, bool (Toy::*func2)(std::string));
		~tellMeAStory() {};
	};
};
