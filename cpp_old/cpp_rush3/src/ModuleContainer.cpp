/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** cpp file
*/

#include "../Include/ModuleContainer.hpp"

ModuleContainer::ModuleContainer()
{
	_tmp = getCPUInfo();
	_mod.push_back(MonitorModule("nbcpu", (int)_tmp->size()));
	getCPUPercent();
	getRAM();
	getCPUModelAndFrequency();
}

ModuleContainer::~ModuleContainer()
{
	delete _tmp;
}

void ModuleContainer::Refresh()
{
	_mod.clear();
	getCPUPercent();
	_mod.push_back(MonitorModule("nbcpu", (int)_tmp->size()));
	getRAM();
	getCPUModelAndFrequency();
}

int ModuleContainer::getNetRead() const
{
  return netRead;
}

int ModuleContainer::getNetWrite() const
{
  return netWrite;
}

void ModuleContainer::getCPUModelAndFrequency()
{
	std::ifstream file("/proc/cpuinfo");
	std::string line;
	size_t i;

	while (std::getline(file, line))
		if (line.compare(0, 10, "model name") == 0)
			break;
	for (i = line.size(); line[i] != ' ' && i != 0; i--);
	_mod.push_back(MonitorModule("cpumodel", line.substr(13, i - 13)));
	_mod.push_back(MonitorModule("cpufrequency", line.substr(i + 1)));
}

void ModuleContainer::getRAM()
{
	std::ifstream file("/proc/meminfo");
	std::string line;
	float nb[2] {0, 0};
	size_t x;

	for (size_t i = 0; i != 2; i++) {
		std::getline(file, line);
		for (x = 0; !(line[x] <= '9' && line[x] >= '0'); x++);
		for (; (line[x] <= '9' && line[x] >= '0'); x++)
			nb[i] = nb[i] * 10 + (line[x] - 48);
	}
	_mod.push_back(MonitorModule("ram", (float)(100.0 - (nb[1] / nb[0]) * 100.0)));
}
