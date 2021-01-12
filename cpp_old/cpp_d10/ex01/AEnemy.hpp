/*
** EPITECH PROJECT, 2018
** AEnemy.hpp
** File description:
** 
*/

#ifndef AENEMY_HPP_
# define AENEMY_HPP_

# include <iostream>
# include <string>

class  AEnemy
{
public:
	AEnemy(int hp, const std::string &type);
	virtual ~AEnemy();
	virtual void takeDamage(int damage);
	std::string getType() const;
	int getHP() const;
protected:
	std::string const Type;
	int health;
};

#endif
