/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
# define SORCERER_HPP_

#include <iostream>
#include <string>
#include "Victim.hpp"

class Victim;

class Sorcerer
{
public:
	Sorcerer(std::string, std::string);
	~Sorcerer();
	void polymorph(const Victim &) const;
	std::string name;
	std::string title;
};

std::ostream &operator<<(std::ostream &lop, Sorcerer &rop);


#endif /* !SORCERER_HPP_ */
