/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
	#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string name);
		~KoalaDoctor();
        void diagnose(SickKoala *patient);
        void timeCheck();
	protected:
	private:
        bool working;
        std::string name;
};

#endif /* !KOALADOCTOR_HPP_ */
