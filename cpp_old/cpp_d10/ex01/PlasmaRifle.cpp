/*
** EPITECH PROJECT, 2018
** PlasmaRifle.cpp
** File description:
**
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("PlasmaRifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
