/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy::AEnemy(170, "Super Mutant")
{
	std::cout << "Gaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}
