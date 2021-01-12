/*
** EPITECH PROJECT, 2018
** AEnemy.cpp
** File description:
** 
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : Type(type), health(hp)
{
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
	if (damage > 0)
		health -= damage;
}

std::string AEnemy::getType() const
{
	return this->Type;
}

int AEnemy::getHP() const
{
	return this->health;
}
