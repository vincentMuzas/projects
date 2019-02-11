/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** OsModule
*/

#include "OsModule.hpp"

OsModule::OsModule()
{
	this->types.push_back(this->END);
}

OsModule::~OsModule()
{
}

void OsModule::refresh()
{
	this->data.clear();
	this->types.clear();

	struct utsname data;
	if (uname(&data) == 0) {
		this->data.push_back(new std::string("dist: " + 
			std::string(data.version)));
		this->types.push_back(this->STRING);
		this->data.push_back(new std::string("kernel: " + 
			std::string(data.release)));
		this->types.push_back(this->STRING);
	}
	this->types.push_back(this->END);
}

std::vector<void *> OsModule::getData()
{
	return (data);
}

std::vector<int> OsModule::getTypes()
{
	return (types);
}