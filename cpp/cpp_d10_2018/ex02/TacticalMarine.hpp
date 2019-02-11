/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** TacticalMarine
*/

#ifndef TACTICALMARINE_HPP_
	#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>
#include <vector>

class TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine();
		~TacticalMarine();
		ISpaceMarine *clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
	protected:
	private:
};

#endif /* !TACTICALMARINE_HPP_ */
