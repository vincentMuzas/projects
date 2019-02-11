/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
	#define SICKKOALA_HPP_

#include <string>
#include <iostream>
#include <algorithm>

class SickKoala {
	public:
		SickKoala(std::string name);
		~SickKoala();
        	void poke();
	        bool takeDrug(std::string str);
        	void overDrive(std::string str);
			std::string getName();
	protected:
	private:
        	std::string name;

};

#endif /* !SICKKOALA_HPP_ */
