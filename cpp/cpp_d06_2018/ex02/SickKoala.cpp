/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name) : name(name)
{
}

SickKoala::~SickKoala()
{
	std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!\n";
}

void SickKoala::poke()
{
	std::cout << "Mr." << this->name << ": Gooeeeeerrk!!\n";
}

bool SickKoala::takeDrug(std::string str)
{
	bool ret = true;
	std::string copy (str);
	std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
	if (copy == "mars") {
		std::cout << "Mr." << this->name << ": Mars, and it kreogs!\n";
	}
	else if (str == "Buronzand") {
		std::cout << "Mr." << this->name << ": And you'll sleep right away!\n";
	}
	else {
		std::cout << "Mr." << this-> name << ": Goerkreog!\n";
		ret = false;
	}
	return (ret);
}

void SickKoala::overDrive(std::string str)
{
	std::string cpy(str);
	std::string str2("Kreog!");

	while (cpy.find(str2) != std::string::npos)
		cpy.replace(cpy.find(str2), str2.length(), "1337");
	std::cout << "Mr." << this->name << ": " << cpy << std::endl;
}