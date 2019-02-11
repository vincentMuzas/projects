/*
** EPITECH PROJECT, 2018
** Random.hpp
** File description:
** 
*/

#include "../includes/Random.hpp"

Random::Random()
{
	srandom(std::time(nullptr));
}

Random::~Random()
{
}

unsigned int Random::getInt()
{
	return (random());
}
