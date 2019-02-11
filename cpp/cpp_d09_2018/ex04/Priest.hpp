/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
	#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : public Mage {
	public:
		Priest(const std::string &name, int level);
		~Priest(){}
		int CloseAttack();
		int RangeAttack();
		void Heal();
		void RestorePower();

	protected:
	private:
};

#endif /* !PRIEST_HPP_ */
