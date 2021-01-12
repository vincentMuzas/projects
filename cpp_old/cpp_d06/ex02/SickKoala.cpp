//
// EPITECH PROJECT, 2018
// SickKoala.cpp
// File description:
//
//

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str) : name(str)
{
}

SickKoala::~SickKoala()
{
	std::cout << "Mr." << this->name
		  << ": Kreooogg !! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
	std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(";
}

bool SickKoala::takeDrug(std::string str)
{
	std::string copy = str;
	std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

	if (copy == "mars")
		std::cout << "Mr." << this->name
			  << ": Mars , and it kreogs!" << std::endl;
	else if (str == "Buronzand")
		std::cout << "Mr." << this->name
			  << ": And you 'll sleep right away!;" << std::endl;
	else {
		std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
		return false;
	}
	return true;
}

void SickKoala::overDrive(std::string str)
{
	std::string str1(str);
	std::string str2 = "Kreog!";

	while (str1.find(str2) != std::string::npos)
		str1.replace(str1.find(str2), str2.length(), "1337!");
	std::cout << "Mr." << this->name << ": " << str1 << std::endl;
}
