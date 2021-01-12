/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	LittlePony.hpp
*/

#pragma once

#include "Toy.hpp"

class	LittlePony : public Toy {
public:
	LittlePony(const std::string &name = "Little Pony");
	~LittlePony();

	bool	isTaken() const;
};
