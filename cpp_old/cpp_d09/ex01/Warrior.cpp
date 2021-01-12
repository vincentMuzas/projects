/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "Warrior.hpp"


Warrior::Warrior(const std::string &name, int level)
	: Character(name, level)
{
	_pv = 100;
	_power = 100;
	str = 12;
	stamina = 12;
	intel = 6;
	spirit = 5;
	agi = 7;
	Range = Character::RANGE;
	weaponName = "hammer";
	std::cout << "I'm " << name
		  << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG"
		  << std::endl;
}

int Warrior::CloseAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 30)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " strikes with his "
			  << this->weaponName << std::endl;
		dealt = 20 + this->str;
		this->_power -= 30;
	}
	return dealt;
}

int Warrior::RangeAttack()
{
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " intercepts" << std::endl;
		this->Range = this->CLOSE;
		this->_power -= 10;
	}
	return 0;
}

