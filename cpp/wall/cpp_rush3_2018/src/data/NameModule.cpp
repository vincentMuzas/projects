/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** NameModule
*/

#include "NameModule.hpp"

NameModule::NameModule()
{
	this->types.push_back(this->END);
}

NameModule::~NameModule()
{
}

void NameModule::refresh()
{
	this->data.clear();
	this->types.clear();
	std::ifstream file("/proc/sys/kernel/hostname");
	std::stringstream buffer;
	if (file.good()) {
		buffer << file.rdbuf();
		this->data.push_back(new std::string(buffer.str()));
		this->types.push_back(this->STRING);
		file.close();
	}
	buffer.clear();
	this->data.push_back(new std::string(getlogin()));
	this->types.push_back(this->STRING);
	this->types.push_back(this->END);
}

std::vector<void *> NameModule::getData()
{
	return (data);
}

std::vector<int> NameModule::getTypes()
{
	return (types);
}