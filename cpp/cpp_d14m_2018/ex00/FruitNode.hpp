/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
	#define FRUITNODE_HPP_

#include "Fruit.hpp"

struct FruitNode {
	Fruit *fruit;
	FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
