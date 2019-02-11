/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
	#define PALADIN_HPP_

#include "Character.hpp"
#include "Priest.hpp"
#include "Warrior.hpp"

class Paladin : public Warrior, public Priest {
	public:
		Paladin(const std::string &name, int level);
		~Paladin(){}
		int CloseAttack();
		int RangeAttack();
		void RestorePower();
		void Heal();
		int Intercept() {return (Warrior::RangeAttack());};
		
	protected:
	private:
};

#endif /* !PALADIN_HPP_ */
