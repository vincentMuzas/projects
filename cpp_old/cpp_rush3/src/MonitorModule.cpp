/*
** EPITECH PROJECT, 2018
** 
** File description:
** cpp file
*/

#include "../Include/MonitorModule.hpp"

MonitorModule::MonitorModule(std::string mod, float value)
	: _mod(mod), _type(typeid(float).name()), _Fvalue(value)
{
}

MonitorModule::MonitorModule(std::string mod, int value)
	: _mod(mod), _type(typeid(int).name()), _Ivalue(value)
{
}

MonitorModule::MonitorModule(std::string mod, std::string value)
	: _mod(mod), _type(typeid(std::string).name()), _name(value)
{
}

MonitorModule::~MonitorModule()
{
}

std::string MonitorModule::getSValue() const
{
	return _name;
}

float MonitorModule::getFValue() const
{
	return _Fvalue;
}

int MonitorModule::getIValue() const
{
	return _Ivalue;
}

std::string MonitorModule::getModul() const
{
	return _mod;
}