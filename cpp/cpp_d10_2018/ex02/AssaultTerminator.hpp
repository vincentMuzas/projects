/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** AssaultTerminator
*/

#ifndef ASSAULTTERMINATOR_HPP_
	#define ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>
#include <vector>

class AssaultTerminator : public ISpaceMarine {
	public:
		AssaultTerminator();
		~AssaultTerminator();
		ISpaceMarine *clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
	protected:
	private:
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
