/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
	#define AWEAPON_HPP_

#include <iostream>
#include <string>

class AWeapon {
	public:
		AWeapon(const std::string &name, int apcost, int damage);
		~AWeapon();
		std::string getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
	protected:
		std::string name;
		int apcost;
		int damage;
	private:
};

#endif /* !AWEAPON_HPP_ */
