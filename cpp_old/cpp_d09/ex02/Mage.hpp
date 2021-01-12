/*
** EPITECH PROJECT, 2018
** Warrior.hpp
** File description:
** 
*/

#ifndef MAGE_H_
# define MAGE_H_

# include "Character.hpp"

class Mage : public Character
{
public:
	Mage(const std::string &name, int level);
	~Mage()
		{
		}
	int CloseAttack();
	int RangeAttack();
	void RestorePower();
private:
	std::string weaponName;
};


#endif /* !MAGE_H_ */
