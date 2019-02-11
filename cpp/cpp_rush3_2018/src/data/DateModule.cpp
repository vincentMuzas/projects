/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** DateModule
*/

#include "DateModule.hpp"

DateModule::DateModule()
{
	this->types.push_back(this->END);
}

DateModule::~DateModule()
{
}

void DateModule::refresh()
{
	this->data.clear();
	this->types.clear();

	char buffer[80];
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d/%m/%Y", timeinfo);
	this->data.push_back(new std::string(buffer));
	this->types.push_back(this->STRING);

	strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
	this->data.push_back(new std::string(buffer));
	this->types.push_back(this->STRING);

	this->types.push_back(this->END);
}

std::vector<void *> DateModule::getData()
{
	return (data);
}

std::vector<int> DateModule::getTypes()
{
	return (types);
}