/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** main
*/

#include "NameModule.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

int main()
{
	NameModule name;

	name.refresh();
	for (unsigned int i = 0; i < name.getTypes().size(); i++)
	{
		if (name.getTypes()[i] == name.END)
			continue;
		if (name.getTypes()[i] == name.STRING)
			std::cout << *static_cast<std::string *>(name.getData()[i]) << std::endl;
		if (name.getTypes()[i] == name.INT)
			std::cout << *static_cast<int *>(name.getData()[i]) << std::endl;
	}
}