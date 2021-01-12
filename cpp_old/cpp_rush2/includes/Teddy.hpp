/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	Teddy.hpp
*/

#pragma once

#include "Toy.hpp"

class	Teddy : public Toy {
public:
	Teddy(const std::string &name = "Teddy");
	~Teddy();

	bool	isTaken() const;
};
