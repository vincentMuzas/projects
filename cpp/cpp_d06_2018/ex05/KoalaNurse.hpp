/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
	#define KOALANURSE_HPP_

#include "SickKoala.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

class KoalaNurse {
	public:
		KoalaNurse(int id);
		~KoalaNurse();
		void giveDrug(std::string str, SickKoala *patient);
		std::string readReport(std::string filename);
		void timeCheck();
		int getId();
	protected:
	private:
		bool working;
		int id;
};

#endif /* !KOALANURSE_HPP_ */
