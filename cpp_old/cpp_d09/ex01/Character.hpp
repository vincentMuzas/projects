/*
** EPITECH PROJECT, 2018
** Character.hpp
** File description:
**
*/


#ifndef CHARACTER_H_
# define CHARACTER_H_

# include <string>
# include <iostream>

class Character
{
public:
	Character(const std::string &name, int level);
	~Character()
		{
		}
	static const int CLOSE = 0;
	static const int RANGE = 1;
	int getLvl() const;
	int getPv() const;
	int getPower() const;
	const std::string &getName() const;
	int CloseAttack();
	int RangeAttack();
	void Heal();
	void RestorePower();
	void TakeDamage(int i);
	int Range;
protected:
	const std::string _name;
	int _level;
	int _pv;
	int _power;
	int str;
	int stamina;
	int intel;
	int spirit;
	int agi;
};

#endif /* !CHARACTER_H_ */
