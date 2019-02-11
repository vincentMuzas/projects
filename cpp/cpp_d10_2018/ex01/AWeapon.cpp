/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
: name(name), apcost(apcost), damage(damage)
{
}

AWeapon::~AWeapon()
{
}

int AWeapon::getAPCost() const
{
	return (apcost);
}

int AWeapon::getDamage() const
{
	return (damage);
}

std::string AWeapon::getName() const
{
	return (name);
}