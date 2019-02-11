/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Squad
*/

#ifndef SQUAD_HPP_
	#define SQUAD_HPP_

#include "ISquad.hpp"
#include <string>
#include <iostream>
#include <vector>

class Squad : public ISquad {
	public:
		Squad();
		~Squad();
		int getCount() const;
		ISpaceMarine *getUnit(int index);
		int push(ISpaceMarine *unit);
	protected:
		std::vector<ISpaceMarine *> marineList;
	private:
};

#endif /* !SQUAD_HPP_ */
