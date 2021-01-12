/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "Priest.hpp"


Priest::Priest(const std::string &name, int level)
	: Character(name, level)
{
	_pv = 100;
	_power = 100;
	str = 4;
	stamina = 4;
	intel = 42;
	spirit = 21;
	agi = 2;
	Range = Character::RANGE;
	weaponName = "bored";
	std::cout << name
		  << " enters in the order"
		  << std::endl;
}

void Priest::Heal()
{
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		this->_pv += 70;
		this->_power -= 10;
		if (this->_pv > 100)
			this->_pv = 100;
		std::cout << this->_name << " casts a little heal spell"
			  << std::endl;
	}
}

int Priest::CloseAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " uses a spirit explosion"
			  << std::endl;
		this->_power -= 10;
		dealt += 10 + this->spirit;
		this->Range = this->RANGE;
	}
	return dealt;
}

int Priest::RangeAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 25)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " lauches a fire ball" << std::endl;
		dealt += 20 + this->spirit;
		this->_power -= 25;
	}
	return dealt;
}

