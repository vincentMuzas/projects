/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Peon
*/

#ifndef PEON_HPP_
# define PEON_HPP_

#include "Sorcerer.hpp"

class Victim;

class Peon : public Victim
{
public:
	Peon(std::string);
	~Peon();
	void getPolymorphed() const override;
};

#endif /* !PEON_HPP_ */
