/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair) : _side(300), _maxWarp(9),
	_shield(100),
	_weaponFrequency(weaponFrequency), _repair(repair)
{
	std::cout << "We are the Borgs."<<
	" Lower your shields and surrender yourselves unconditionally.\nYour" <<
	" biological characteristics and technologies will be assimilated.\n"
	<< "Resistance is futile.\n";
}

void Borg::Ship::checkCore()
{
	if (this->_core->checkReactor()->_stability == true)
		std::cout << "Everything is in order.\n";
	else
		std::cout << "Critical failure imminent.\n";
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
}

bool Borg::Ship::move(int warp, Destination d)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	warp <= this->_maxWarp && d != _location) {
		ret = true;
		this->_location = d;
	}
	return (ret);
}

bool Borg::Ship::move(int warp)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	warp <= this->_maxWarp && _home != _location) {
		ret = true;
		this->_location = _home;
	}
	return (ret);
}

bool Borg::Ship::move(Destination d)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	d != _location) {
		ret = true;
		this->_location = d;
	}
	return (ret);
}

bool Borg::Ship::move()
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	_home != _location) {
		ret = true;
		this->_location = _home;
	}
	return (ret);
}

int Borg::Ship::getShield()
{
	return (_shield);
}

void Borg::Ship::setShield(int shield)
{
	this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
	return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
	_weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
	return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
	_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
	target->setShield(target->getShield() - _weaponFrequency);
	std::cout << "Firing on target with " << _weaponFrequency
		<< "GW frequency.\n";
}

void Borg::Ship::fire(Federation::Ship *target)
{
	target->getCore()->checkReactor()->setStability(false);
	std::cout << "Firing on target with " << _weaponFrequency
		<< "GW frequency.\n";

}

void Borg::Ship::repair()
{
	if (_repair > 0) {
		std::cout << "Begin shield re-initialisation...";
		_repair --;
		_shield = 100;
		std::cout << " Done. Awaiting further instructions.\n";
	}
	else
		std::cout << "Energy cells depleted, shield weakening.\n";
}