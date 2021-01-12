/*
** EPITECH PROJECT, 2018
** AWeapon.cpp
** File description:
**
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
	Name(name),
	APCost(apcost),
	Damage(damage)
{
}


AWeapon::~AWeapon()
{
}

void AWeapon::attack() const
{
}

int AWeapon::getDamage() const
{
	return this->Damage;
}

int AWeapon::getAPCost() const
{
	return this->APCost;
}

std::string AWeapon::getName() const
{
	return this->Name;
}
