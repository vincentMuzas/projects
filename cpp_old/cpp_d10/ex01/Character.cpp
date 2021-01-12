/*
** EPITECH PROJECT, 2018
** Character.cpp
** File description:
**
*/

#include "Character.hpp"

Character::Character(const std::string &name) : AP(40), weapon(NULL), name(name)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
	this->AP += 10;
	if (this->AP > 40)
		this->AP = 40;
}

void Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
	if (this->weapon != NULL) {
		enemy->takeDamage(this->weapon->getDamage());
		std::cout << this->name << " attacks " << enemy->getType()
			  << "with a " << this->weapon->getName() << std::endl;
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}
