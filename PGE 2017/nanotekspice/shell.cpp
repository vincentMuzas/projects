/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** shell
*/

#include "includes/nano.hpp"

shell::shell(std::string filename)
{
	std::ifstream file(filename);
	char line[256];

	while (file) {
		file.getline(line, 256);
		shell::to_parse(line);
	}
}

shell::~shell()
{
}

void shell::to_parse(std::string line)
{
	static std::string type("");
	strtab tab;

	if (line.front() != '#') {
		if (line == ".chipsets:" || line == ".links:")
			type = line;
		if (line.length() != 0) {
			tab.setstr(line);
			tab.clear();
			std::cout << tab.getstr() << std::endl;
		}
	}
}