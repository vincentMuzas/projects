/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
	public:
		Character(const std::string &name);
		~Character();
		void recoverAP();
		void equip(AWeapon *weapon);
		void attack(AEnemy *enemy);
		std::string const getName() const;
		int getAP() {return (ap);};
		AWeapon *getWeapon() {return (weapon);};
	protected:
		const std::string name;
		int ap;
		AWeapon *weapon;
	private:
};

std::ostream &operator<<(std::ostream &lop, Character &rop);

#endif /* !CHARACTER_HPP_ */
