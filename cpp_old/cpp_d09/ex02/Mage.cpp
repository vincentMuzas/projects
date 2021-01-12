/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "Mage.hpp"


Mage::Mage(const std::string &name, int level)
	: Character(name, level)
{
	_pv = 100;
	_power = 100;
	str = 6;
	stamina = 6;
	intel = 12;
	spirit = 11;
	agi = 7;
	Range = Character::RANGE;
	weaponName = "hammer";
	std::cout << name << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " blinks" << std::endl;
		this->_power -= 10;
		this->Range = this->RANGE;
	}
	return 0;
}

int Mage::RangeAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 25)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " launches a fire ball" << std::endl;
		dealt = 20 + this->spirit;
		this->_power -= 25;
	}
	return dealt;
}

void Mage::RestorePower()
{
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else {
		this->_power += 50 + this->intel;
		if (this->_power > 100)
			this->_power = 100;
		std::cout << this->_name << " takes a mana potion" << std::endl;
	}
}
