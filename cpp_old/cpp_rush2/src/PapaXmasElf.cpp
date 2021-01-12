/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	PapaXmasElf.hpp
*/

#include "../includes/PapaXmasElf.hpp"

PapaXmasElf::PapaXmasElf()
{
	this->p_table = createTable();
	this->p_belt = createConveyorBelt();
}

PapaXmasElf::~PapaXmasElf()
{
	if (this->p_table != nullptr) {
		delete this->p_table;
	}
	if (this->p_belt != nullptr) {
		delete this->p_belt;
	}
}

void	PapaXmasElf::setTable(ITable *table)
{
	if (this->p_table != nullptr) {
		delete this->p_table;
	}
	this->p_table = table;
}

void	PapaXmasElf::setConveyorBelt(IConveyorBelt *belt)
{
	if (this->p_belt != nullptr) {
		delete this->p_belt;
	}
	this->p_belt = belt;
}

void	PapaXmasElf::makeAllGifts()
{
	bool	res = true;

	while (res) {
		res = this->makeGift();
	}
}

bool	PapaXmasElf::makeGift()
{
	if (this->p_table == nullptr || this->p_belt == nullptr) {
		std::cerr << NO_TABLE_CONVOYER << std::endl;
		return (false);
	}
	Toy	*toy = this->searchToy();
	Box	*box = this->searchEmptyBox();
	if (toy == nullptr || box == nullptr) {
		std::cerr << CANT_CREATE_GIFT << std::endl;
		return (false);
	}
	this->wrapToy(toy, box);
	GiftPaper	*gp = this->searchEmptyGiftPaper();
	if (gp == nullptr) {
		std::cerr << CANT_CREATE_GIFT << std::endl;
		return (false);
	}
	this->wrapBox(box, gp);
	this->sendGift(gp);
	return (true);
}

void		PapaXmasElf::sendGift(GiftPaper *gift)
{
	bool success = this->p_belt->set(0, gift);
	if (!success) {
		this->emptyConveyor();
		success = this->p_belt->set(0, gift);
	}
	if (success) {
		*this->p_table -= gift;
		this->p_belt->OUT();
	} else {
		std::cerr << ERROR_NOT_EMPTY << std::endl;
	}

}

void		PapaXmasElf::wrapToy(Toy *toy, Box *box)
{
	box->openMe();
	box->wrapMeThat(toy);
	*this->p_table -= toy;
	std::cout << ELVES_WRAP_OBJ << std::endl;
	box->closeMe();
}
void		PapaXmasElf::wrapBox(Box *box, GiftPaper *paper)
{
	paper->wrapMeThat(box);
	*this->p_table -= box;
	std::cout << ELVES_WRAP_OBJ << std::endl;
}

bool		PapaXmasElf::emptyConveyor()
{
	if (this->p_belt->isEmpty()) {
		return (true);
	}
	if (this->p_table->isFull()) {
		return (false);
	}
	Object	*content = this->p_belt->getFirst();
	*this->p_table << content;
	this->p_belt->remove(content);
	std::cout << ELVES_TAKE_WRAP << std::endl;
	return (true);
}

bool		PapaXmasElf::pullNext()
{
	if (this->p_belt->isEmpty()) {
		return (this->p_belt->IN());
	}
	if (this->p_table->isFull()) {
		return (false);
	}
	Object	*content = this->p_belt->getFirst();
	this->p_table->add(content);
	this->p_belt->remove(content);
	std::cout << ELVES_TAKE_WRAP << std::endl;
	this->p_belt->IN();
	return (true);
}

Toy	*PapaXmasElf::searchToy()
{
	Object	*s = this->p_table->getFirstOfType(Object::ObjectType::Toy);
	if (s != nullptr) {
		Toy	*t = static_cast<Toy *>(s);
		t->isTaken();
		return (t);
	}
	return (nullptr);
}

Box	*PapaXmasElf::searchEmptyBox()
{
	Object	*s = this->p_table->getFirstOfType(Object::ObjectType::Box);
	while (s != nullptr) {
		Box	*b = static_cast<Box *>(s);
		if (b->isEmpty())
			return (b);
		this->p_table->remove(b);
		s = this->p_table->getFirstOfType(Object::ObjectType::Box);
	}
	do {
		s = this->p_belt->getFirstOfType(Object::ObjectType::Box);
		if (s != nullptr) {
			Box	*b = static_cast<Box *>(s);
			if (b->isEmpty())
				return (b);
			this->p_belt->remove(b);
		}
	} while (this->pullNext());
	return (nullptr);
}

GiftPaper	*PapaXmasElf::searchEmptyGiftPaper()
{
	Object	*s = this->p_table->getFirstOfType(Object::GiftPaper);
	while (s != nullptr) {
		GiftPaper	*gp = static_cast<GiftPaper *>(s);
		if (gp->isEmpty())
			return (gp);
		this->p_table->remove(gp);
		s = this->p_table->getFirstOfType(Object::GiftPaper);
	}
	do {
		s = this->p_belt->getFirstOfType(Object::GiftPaper);
		if (s != nullptr) {
			GiftPaper	*gp = static_cast<GiftPaper *>(s);
			if (gp->isEmpty())
				return (gp);
			this->p_belt->remove(gp);
		}
	} while (this->pullNext());
	return (nullptr);
}
