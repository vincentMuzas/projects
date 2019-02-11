/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name) : name(name)
{
	ap = 40;
	weapon = nullptr;
}

void Character::recoverAP()
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
	if (this->weapon != nullptr && ap - weapon->getAPCost() < 0)
		return;
	std::cout << name << " attacks " << enemy->getType()
	<< " with a " << weapon->getName() << std::endl;

	weapon->attack();
	enemy->takeDamage(weapon->getDamage());
	ap -= weapon->getAPCost();
	if (enemy->getHP() <= 0) {
		delete enemy;
	}
}

std::string const Character::getName() const
{
	return (name);
}

std::ostream &operator<<(std::ostream &lop, Character &rop)
{
	if (rop.getWeapon() != nullptr)
		lop << rop.getName() << " has " << rop.getAP() <<
		" AP and wields a " << rop.getWeapon()->getName() << std::endl;
	else
		lop << rop.getName() << " has " << rop.getAP() <<
		" AP and is unarmed" << std::endl;
	return lop;
}

Character::~Character()
{
}
