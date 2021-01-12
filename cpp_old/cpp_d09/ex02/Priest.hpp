/*
** EPITECH PROJECT, 2018
** Warrior.hpp
** File description:
** 
*/

#ifndef PRIEST_H_
# define PRIEST_H_

# include "Character.hpp"

class Priest : public Character
{
public:
	Priest(const std::string &name, int level);
	~Priest()
		{
		}
	int CloseAttack();
	int RangeAttack();
	void Heal();
private:
	std::string weaponName;
};


#endif /* !PRIEST_H_ */
