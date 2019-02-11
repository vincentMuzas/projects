/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : name(name), working(false)
{
	std::cout << "Dr." << name << ": I'm Dr."<< name << "! How do you kreog?\n";
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
	std::string medocs[] = {"mars", "Buronzand",
		"Viagra", "Extasy", "Eucalyptus leaf"};
	int index = random() % 5;
	std::cout << "Dr." << this->name << ": So what's goerking you Mr."
		<< patient->getName() << "?\n";
	std::ofstream outfile(patient->getName() + ".report");
	outfile << medocs[index];
	outfile.close();
}

void KoalaDoctor::timeCheck()
{
	if (this->working == false)
		std::cout << "Dr. " << this->name << " Time to get to work!\n";
	else if (this->working == true)
		std::cout << "Dr. " << this->name <<
			" Time to go home to my eucalyptus forest!\n";
	this->working = !this->working;
}
