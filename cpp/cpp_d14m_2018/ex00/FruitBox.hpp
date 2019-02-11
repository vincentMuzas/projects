/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
	#define FRUITBOX_HPP_

#include "FruitNode.hpp"
#include "Fruit.hpp"
#include <memory>

class FruitBox {
	public:
		FruitBox(int size);
		~FruitBox();
		int nbFruits() const;
		bool putFruit(Fruit *f);
		Fruit *pickFruit();
		FruitNode *head() {return box;};
	protected:
		int _maxSize;
		FruitNode *box;
	private:
};

#endif /* !FRUITBOX_HPP_ */
