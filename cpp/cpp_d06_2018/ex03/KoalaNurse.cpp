/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id) : id(id), working(false)
{
}

KoalaNurse::~KoalaNurse()
{
	std::cout << "Nurse " << id << " Finally some rest!\n";
}

void KoalaNurse::giveDrug(std::string str, SickKoala *patient)
{
	patient->takeDrug(str);
}

std::string KoalaNurse::readReport(std::string filename)
{
	std::string ret("");
	size_t lastindex = filename.find_last_of(".");
	std::string rawname = filename.substr(0, lastindex);
	std::stringstream ss;
	std::ifstream fs;
	if (filename.substr(filename.find_last_of(".") + 1) == "report") {
		fs.open(filename);
		if (fs.is_open()) {
			ss << fs.rdbuf();
			ret = ss.str();
			std::cout << "Nurse " << this->id << ": Kreog! Mr."
				<< rawname << " needs a "<< ret << "!\n";
			fs.close();
		}
	}
	return (ret);
}

void KoalaNurse::timeCheck()
{
	if (this->working == false)
		std::cout << "Nurse " << this->id << " Time to get to work!\n";
	else if (this->working == true)
		std::cout << "Nurse " << this->id <<
			" Time to go home to my eucalyptus forest!\n";
	this->working = !this->working;
}