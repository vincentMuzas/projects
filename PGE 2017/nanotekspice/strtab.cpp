/*
** EPITECH PROJECT, 2018
** nano
** File description:
** strtab
*/

#include "includes/nano.hpp"

std::string *strtab::split_string()
{
	auto counter = 0;
	std::string *strWords = new std::string[5];
	for (unsigned int i = 0; i < this->str.length() && i < 5; i++){
		if (this->str[i] == ' ' && this->str[i + 1] != ' ')
			counter++;
		else
			strWords[counter] += this->str[i];
	}
	return strWords;
}


void strtab::clear()
{
	std::string copy = "";
	auto i = 0;
	while (this->str[i] != 0) {
		if ((this->str[i] == ' ' || this->str[i] == '\t') &&
		(this->str[i + 1] == ' ' || this->str[i + 1] == '\t'));
		else if (this->str[i] != '\t')
			copy += this->str.c_str()[i];
		else
			copy += " ";
		i++;
	}
	this->str = copy;
}

void strtab::setstr(std::string string)
{
	str = string;
}

std::string strtab::getstr()
{
	return str;
}