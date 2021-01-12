/*
** EPITECH PROJECT, 2018
** ConveyorBeltRand.cpp
** File description:
**
*/

#include "../includes/ConveyorBeltRand.hpp"

ConveyorBeltRand::ConveyorBeltRand() :
	PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{
}

bool ConveyorBeltRand::IN()
{
	if (!this->isEmpty()) {
		std::cerr << ERROR_NOT_EMPTY << std::endl;
		return false;
	}
	unsigned int res = this->p_random.getInt() % 2;

	bool flag = false;
	if (res == 0)
		flag = this->add(new Box("Random Box")) >= 0;
	else
		flag = this->add(new GiftPaper("Multicolor Paper")) >= 0;
	return flag;
}

bool ConveyorBeltRand::OUT()
{
	if (this->isEmpty()) {
		std::cerr << ERROR_IS_EMPTY <<std::endl;
		return false;
	}
	GiftPaper	*gp = dynamic_cast<GiftPaper *>(this->getFirst());
	this->remove(gp);
	this->p_datas.load(gp);
	this->p_datas.generateXMLFile();
	delete gp;
	return true;
}
