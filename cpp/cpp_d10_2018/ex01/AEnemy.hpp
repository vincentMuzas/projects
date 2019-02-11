/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
	#define AENEMY_HPP_

#include <string>
#include <iostream>

class AEnemy {
	public:
		AEnemy(int hp, const std::string &type);
		virtual ~AEnemy();

		virtual void takeDamage(int damage);
		std::string getType() const;
		int getHP() const;

	protected:
		std::string type;
		int hp;
	private:
};

#endif /* !AENEMY_HPP_ */
