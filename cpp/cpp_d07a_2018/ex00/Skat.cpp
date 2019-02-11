/*
** EPITECH PROJECT, 2019
** cpp_d07a_2018
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPack) : _name(name)
{
	_stimPaks = stimPack;
}

Skat::Skat() : _name("bob"), _stimPaks(_stimPaks)
{
}

Skat::~Skat()
{
}

int Skat::stimPaks()
{
	return (_stimPaks);
}

int Skat::stimPaks(int val)
{
	_stimPaks = val;
	return (_stimPaks);
}

const std::string &Skat::name()
{
	return (_name);
}

void Skat::shareStimPaks(int number, Skat &stock)
{
	if (_stimPaks - number >= 0 && number > 0) {
		stock.addStimPaks(number);
		_stimPaks -= number;
		std::cout << "Keep the change.\n";
	}
	else
		std::cout << "Don't be greedy\n";
}

void Skat::addStimPaks(unsigned int stimPack)
{
	if (stimPack == 0)
		std::cout << "Hey boya, did you forget something?\n";
	_stimPaks += stimPack;
}

void Skat::useStimPaks()
{
	if (_stimPaks > 0) {
		std::cout << "Time to kick some ass and chew bubble gum.\n";
		_stimPaks --;
	}
	else
		std::cout << "Mediiiiiic\n";
}

void Skat::status()
{
	std::cout << "Soldier " << _name << " reporting "
	<< _stimPaks << " stimpaks remaining sir!\n";
}