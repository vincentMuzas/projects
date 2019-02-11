/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** Fruit
*/

#include <string>
#include <iostream>

#ifndef FRUIT_HPP_
	#define FRUIT_HPP_

class Fruit {
	public:
		Fruit(int vitamins, std::string name);
		~Fruit();
		std::string getName();
		int getVitamins();
	protected:
		std::string _name;
		int _vitamins;
	private:
};

#endif /* !FRUIT_HPP_ */
