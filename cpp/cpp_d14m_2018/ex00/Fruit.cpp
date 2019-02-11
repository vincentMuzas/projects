/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(int vitamins, std::string name)
{
	_vitamins = vitamins;
	_name = name;
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins()
{
	return (_vitamins);
}

std::string Fruit::getName()
{
	return (_name);
}