/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** container2
*/

#include "../Include/ModuleContainer.hpp"


void ModuleContainer::getCPUPercent()
{
	const size_t size = _tmp->size();
	std::vector<CPUData> *tmp = getCPUInfo();

	for(size_t i = 0; i < size; ++i)
	{
		const float t1 = static_cast<float>(GetActiveTime(tmp->at(i)) - GetActiveTime(_tmp->at(i)));
		const float t2 = static_cast<float>(GetOffTime(tmp->at(i)) - GetOffTime(_tmp->at(i)));
		const float tt = t1 + t2;
		_mod.push_back(MonitorModule("cpu" + _tmp->at(i).cpu, static_cast<float>(100.f * t1 / tt)));
	}
	delete _tmp;
	_tmp = std::move(tmp);
}

int ModuleContainer::getIValue(const std::string &name) const
{
	int tmp = 0;

	for (auto it = _mod.begin(); it != _mod.end(); it++)
		if (it->getModul() == name)
			tmp = it->getIValue();
	return tmp;
}

float ModuleContainer::getFValue(const std::string &name) const
{	
	float tmp = 0;

	for (auto it = _mod.begin(); it != _mod.end(); it++)
		if (it->getModul() == name)
			tmp = it->getFValue();
	return tmp;
}

std::string ModuleContainer::getSValue(const std::string &name) const
{
	std::string tmp("");
	for (auto it = _mod.begin(); it != _mod.end(); it++)
		if (it->getModul() == name)
			tmp = it->getSValue();
	return tmp;
}