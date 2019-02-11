/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type)
: type(type), hp(hp)
{
}

void AEnemy::takeDamage(int damage)
{
	if (damage > 0) {
		this->hp -= damage;
	}
}

std::string AEnemy::getType() const
{
	return (type);
}

int AEnemy::getHP() const
{
	return (hp);
}

AEnemy::~AEnemy()
{
}
