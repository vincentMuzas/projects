/*
** EPITECH PROJECT, 2018
** Warrior.hpp
** File description:
** 
*/

#ifndef WARRIOR_H_
# define WARRIOR_H_

# include "Character.hpp"

class Warrior : public Character
{
public:
	Warrior(const std::string &name, int level);
	~Warrior()
		{
		}
	int CloseAttack();
	int RangeAttack();
private:
	std::string weaponName;
};


#endif /* !WARRIOR_H_ */
