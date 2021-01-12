/*
** EPITECH PROJECT, 2018
** RadScorpion.hpp
** File description:
**
*/

#ifndef RADSCORPION_HPP_
# define RADSCORPION_HPP_

#include "AEnemy.hpp"

class RedScorpion : public AEnemy
{
public:
	RedScorpion();
	~RedScorpion();
	void takeDamage(int) override;
};

#endif
