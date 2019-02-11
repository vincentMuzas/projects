/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Priest
*/

#include "Priest.hpp"
#include "Character.hpp"

Priest::Priest(const std::string &name, int level)
	: Character(name, level), Mage(name, level)
{	
	_pv = 100;
	_power = 100;
	str = 4;
	stamina = 4;
	intel = 42;
	spirit = 21;
	agi = 2;
	std::cout << name << " enters in the order" << std::endl;
}

int Priest::CloseAttack()
{
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name <<
			" uses a spirit explosion" << std::endl;
		dealt = 10 + this->spirit;
		this->_power -= 10;
	}
	return (dealt);
}

int Priest::RangeAttack() {
	int dealt = 0;

	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 25)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " launches a fire ball" << std::endl;
		dealt = 20 + this->spirit;
		this->Range = this->RANGE;
		this->_power -= 25;
	}
	return dealt;
}
void Priest::Heal() {
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else if (this->_power < 10)
		std::cout << this->_name << " out of power" << std::endl;
	else {
		std::cout << this->_name << " casts a little heal spell" << std::endl;
		this->_pv += 70;
		this->_power -= 10;
		if (this->_pv > 100)
			this->_pv = 100;
	}
}

void Priest::RestorePower() {
	if (this->_pv <= 0)
		std::cout << this->_name << " out of combat" << std::endl;
	else {
		std::cout << this->_name << " takes a mana potion" << std::endl;
		this->_power += 50 + this->intel;
		if (this->_power > 100)
			this->_power = 100;
	}
}