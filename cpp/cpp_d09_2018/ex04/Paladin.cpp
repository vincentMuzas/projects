/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level)
	: Character(name, level), Warrior(name, level), Priest(name, level)
{
	_pv = 100;
	_power = 100;
	str = 9;
	stamina = 10;
	intel = 10;
	spirit = 10;
	agi = 2;
	weaponName = "hammer";
	std::cout << "the light falls on " << name << std::endl;
}

int Paladin::RangeAttack()
{
	return (Mage::RangeAttack());
}

int Paladin::CloseAttack()
{
	return (Warrior::CloseAttack());
}

void Paladin::Heal()
{
	Priest::Heal();
}

void Paladin::RestorePower()
{
	Character::RestorePower();
}