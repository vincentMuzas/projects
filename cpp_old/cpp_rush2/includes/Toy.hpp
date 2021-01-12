/*
** EPITECH PROJECT, 2018
** CPP_Rush2: Santa Claus
** File description:
** A Toy to wrap
*/

#pragma once

#include "Object.hpp"

///
/// @brief A toy to wrap and send.
///
/// Represent a toy used for creating gifts.
///
class	Toy : public Object {
public:
	Toy(const std::string &name);
	virtual	~Toy();
};
