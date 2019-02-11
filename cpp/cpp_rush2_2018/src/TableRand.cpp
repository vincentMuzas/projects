/*
** EPITECH PROJECT, 2018
** ConveyorBeltRand.cpp
** File description:
**
*/

#include "../includes/TableRand.hpp"

TableRand::TableRand() :
	PapaXmasTable::PapaXmasTable()
{
	int i = 0;
	unsigned int res;

	while (i < 10) {
		res = this->p_random.getInt() % 4;
		switch (res) {
		case 0:
			this->add(new Teddy("Random Teddy"));
			break;
		case 1:
			this->add(new LittlePony("Big Little Pony"));
			break;
		case 2:
			this->add(new Box());
			break;
		case 3:
			this->add(new GiftPaper());
			break;
		}
		i++;
	}
}

TableRand::~TableRand()
{
}
