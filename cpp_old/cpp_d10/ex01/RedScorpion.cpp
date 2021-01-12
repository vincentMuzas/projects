/*
** EPITECH PROJECT, 2018
** RedScorpion.cpp
** File description:
** 
*/

#include "RedScorpion.hpp"

RedScorpion::RedScorpion() : AEnemy(80, "RedScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RedScorpion::~RedScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

void RedScorpion::takeDamage(int damage)
{
	if (damage - 3 > 0)
		this->health -= (damage - 3);
}
