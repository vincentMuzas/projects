/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _maxSize(size), box(new FruitNode)
{
	box->fruit = nullptr;
	box->next = nullptr;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
	FruitNode *loc = box;
	int i = 0;

	while (loc != nullptr && loc->next != nullptr) {
		loc = loc->next;
		i++;
	}
	return (i);
}

bool FruitBox::putFruit(Fruit *f)
{
	FruitNode *loc = box;
	int i = 0;

	while (loc != nullptr) {
		if (i >= _maxSize)
			return (false);
		if (loc->next == nullptr) {
			loc->next = new FruitNode;
			loc->fruit = f;
			loc->next->fruit = nullptr;
			loc->next->next = nullptr;
			return (true);
		}
		loc = loc->next;
		i++;
	}
	return (false);
}

Fruit *FruitBox::pickFruit()
{
	if (box == nullptr)
		return (nullptr);
	Fruit *ret = box->fruit;
	box = box->next;
	return (ret);
}