/*
** EPITECH PROJECT, 2018
** Character hpp
** File description:
** 
*/

#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "AEnemy.hpp"
# include "AWeapon.hpp"

class  Character
{
public:
	Character(const std::string &name);
	~Character();
	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(AEnemy *enemy);
	int getAP() const;
	std:: string const getName() const;
private:
	int AP;
	AWeapon *weapon;
	std::string const name;
};

#endif
