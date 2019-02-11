/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(
	int length, int width, std::string name, short maxWarp, int torpedo)
{
	this->_length = length;
	this->_width = width;
	this->_name = "USS " + name;
	this->_maxWarp = maxWarp;
	this->_home = EARTH;
	this->_location = _home;
	this->_shield = 100;
	this->_protonTorpedo = torpedo;
	std::cout << "The ship USS " << name << " has been finished.\n"
	<< "It is " << length << " m in length and " << width <<" m in width.\n"
	<< "It can go to Warp " << maxWarp << "!\n";
	if (torpedo != 0) {
		std::cout<<"Weapons are set: "<< torpedo<<" torpedoes ready.\n";
	}
}
Federation::Starfleet::Ship::Ship()
{
	this->_length = 289;
	this->_width = 132;
	this->_name = "USS Entreprise";
	this->_maxWarp = 6;
	this->_home = EARTH;
	this->_location = _home;
	this->_shield = 100;
	this->_protonTorpedo = 0;
	std::cout << "The ship USS " << _name << " has been finished.\n"
	<< "It is " << _length <<" m in length and "<< _width <<" m in width.\n"
	<< "It can go to Warp " << _maxWarp << "!\n";

}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
	std::cout << this->_name << ": The core is set.\n";
}

void Federation::Starfleet::Ship::checkCore()
{
	std::cout << this->_name << ": The core is " <<
	(this->_core->checkReactor()->_stability == true ? "stable": "unstable")
	<< " at the time.\n";
}

void Federation::Starfleet::Ship::promote(Starfleet::Captain *captain)
{
	this->_captain = captain;
	std::cout << captain->getName() <<": I'm glad to be the captain of the "
	<< this->_name << ".\n";
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	warp <= this->_maxWarp && d != _location) {
		ret = true;
		this->_location = d;
	}
	return (ret);
}

bool Federation::Starfleet::Ship::move(int warp)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	warp <= this->_maxWarp && _home != _location) {
		ret = true;
		this->_location = _home;
	}
	return (ret);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	d != _location) {
		ret = true;
		this->_location = d;
	}
	return (ret);
}

bool Federation::Starfleet::Ship::move()
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	_home != _location) {
		ret = true;
		this->_location = _home;
	}
	return (ret);
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
	if (_protonTorpedo >= 1) {
		this->_protonTorpedo --;
		std::cout << _name << ": Firing on target. "
		<< _protonTorpedo << " torpedoes remaining.\n";
		target->setShield(target->getShield() - 50);
		if (_protonTorpedo <= 0)
			std::cout << _name << ": No more torpedo to fire, "
			<< _captain->getName() << "!\n";
	}
	else {
		std::cout << _name << ": Not enough torpedoes to fire, "
		<< _captain->getName() << "!\n";
	}
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
	if (_protonTorpedo >= torpedoes && torpedoes >= 1) {
		this->_protonTorpedo -= torpedoes;
		std::cout << _name << ": Firing on target. "
		<< _protonTorpedo << " torpedoes remaining.\n";
		target->setShield(target->getShield() - (torpedoes * 50));
		if (_protonTorpedo <= 0)
			std::cout << _name << ": No more torpedo to fire, "
			<< _captain->getName() << "!\n";
	}
	else {
		std::cout << _name << ": Not enough torpedoes to fire, "
		<< _captain->getName() << "!\n";
	}
}

int Federation::Starfleet::Ship::getShield()
{
	return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
	_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
	return (_protonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
	_protonTorpedo = torpedo;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = 1;
	this->_home = VULCAN;
	this->_location = _home;
	std::cout << "The independant ship " << name
	<<" just finished its construction.\n"
	<< "It is " << length << " m in length and " << width<<" m in width.\n";
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
	std::cout << this->_name << ": The core is set.\n";
}

void Federation::Ship::checkCore()
{
	std::cout << this->_name << ": The core is " <<
	(this->_core->checkReactor()->_stability == true ? "stable": "unstable")
	<< " at the time.\n";
}

bool Federation::Ship::move(int warp, Destination d)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	warp <= this->_maxWarp && d != _location) {
		ret = true;
		this->_location = d;
	}
	return (ret);
}

bool Federation::Ship::move(int warp)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	warp <= this->_maxWarp && _home != _location) {
		ret = true;
		this->_location = _home;
	}
	return (ret);
}

bool Federation::Ship::move(Destination d)
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	d != _location) {
		ret = true;
		this->_location = d;
	}
	return (ret);
}

bool Federation::Ship::move()
{
	bool ret = false;
	if (this->_core->checkReactor()->_stability == true &&
	_home != _location) {
		ret = true;
		this->_location = _home;
	}
	return (ret);
}

WarpSystem::Core *Federation::Ship::getCore()
{
	return (_core);
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(-1)
{
}

std::string Federation::Starfleet::Captain::getName()
{
	return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
	return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
	this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
	std::cout << "Ensign " << name << ", awaiting orders.\n";
}