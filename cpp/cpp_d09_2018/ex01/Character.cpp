/*
** EPITECH PROJECT, 2018
** Character.cpp
** File description:
**
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level) : _name(name),
						_level(level)
{
	_pv = 100;
	_power = 100;
	str = 5;
	stamina = 5;
	intel = 5;
	spirit = 5;
	agi = 5;
	Range = Character::CLOSE;
	std::cout << name << " Created" << std::endl;
}

const std::string &Character::getName() const
{
	return this->_name;
}

int Character::getLvl() const
{
	return this->_level;
}

int Character::getPv() const
{
	return this->_pv;
}

int Character::getPower() const
{
	return this->_power;
}

int Character::CloseAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " strikes with a wooden stick"
			  << std::endl;
		dealt = 10 + this->str;
		this->_power -= 10;
	}
	return dealt;
}

int Character::RangeAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " tosses a stone" << std::endl;
		dealt = 5 + this->str;
		this->_power -= 10;
	}
	return dealt;
}

void Character::Heal()
{
	if (this->_pv > 0) {
		std::cout << this->_name << " takes a potion" << std::endl;
		this->_pv += 50;
		if (this->_pv > 100)
			this->_pv = 100;
	} else
		std::cout << this->_name << " out of combat" << std::endl;
}

void Character::RestorePower()
{
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else {
		std::cout << this->_name << " eats" << std::endl;
		this->_power = 100;
	}
}

void Character::TakeDamage(int damage)
{
	this->_pv -= damage;
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else
		std::cout << this->_name << " takes " << damage << " damage"
			  << std::endl;
}
