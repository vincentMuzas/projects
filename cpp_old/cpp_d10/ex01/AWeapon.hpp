/*
** EPITECH PROJECT, 2018
** AWeapon.hpp
** File description:
** 
*/

#ifndef AWEAPON_HPP_
# define AWEAPON_HPP_

# include <iostream>
# include <string>

class  AWeapon
{
public:
	AWeapon(const std::string &name, int apcost, int damage);
	~AWeapon();
	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const;
private:
	const std::string Name;
	const int APCost;
	const int Damage;
};

#endif /* !AWEAPON_HPP_ */
