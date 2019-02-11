/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** MemoryModule
*/

#include "MemoryModule.hpp"

MemoryModule::MemoryModule()
{
	this->types.push_back(this->END);
}

MemoryModule::~MemoryModule()
{
}

static std::string *getMemoryTotal()
{
	std::string *name = new std::string("Total Memory:");

	FILE *cmd = popen("free -m | sed -n '2 p' | tr -s ' ' | cut -d' ' -f 2",
		"r");
	if (cmd != NULL) {
			size_t n;
			char buff[128];

			if ((n = fread(buff, 1, sizeof(buff)-1, cmd)) <= 0)
				return name;

			buff[n - 1] = '\0';

			name->append(buff);
			name->append("kb");
			pclose(cmd);
	}
	return (name);
}

static std::string *getUsedTotal()
{
	std::string *name = new std::string("Used Memory:");

	FILE *cmd = popen("free -m | sed -n '2 p' | tr -s ' ' | cut -d' ' -f 3",
		"r");
	if (cmd != NULL) {
			size_t n;
			char buff[128];

			if ((n = fread(buff, 1, sizeof(buff)-1, cmd)) <= 0)
				return name;

			buff[n - 1] = '\0';

			name->append(buff);
			name->append("kb");
			pclose(cmd);
	}
	return (name);
}



void MemoryModule::refresh()
{
	this->data.clear();
	this->types.clear();

	this->data.push_back(getMemoryTotal());
	this->types.push_back(this->STRING);

	this->data.push_back(getUsedTotal());
	this->types.push_back(this->STRING);

	this->types.push_back(this->END);
}

std::vector<void *> MemoryModule::getData()
{
	return (data);
}

std::vector<int> MemoryModule::getTypes()
{
	return (types);
}