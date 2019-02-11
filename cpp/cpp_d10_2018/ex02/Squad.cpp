/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Squad
*/

#include "Squad.hpp"

Squad::Squad()
{
	
}

Squad::~Squad()
{
	std::vector<ISpaceMarine *>::const_iterator iter = marineList.begin();

	while (!marineList.empty()) {
		delete marineList.front();
		iter = marineList.begin();
		marineList.erase(iter);
	}
}

int Squad::getCount() const
{
	return (marineList.size());
}

ISpaceMarine *Squad::getUnit(int index)
{
	if (index < getCount())
		return (marineList.at(index));
	return (nullptr);
}

int Squad::push(ISpaceMarine *elem)
{
	marineList.push_back(elem);
	return (getCount());
}