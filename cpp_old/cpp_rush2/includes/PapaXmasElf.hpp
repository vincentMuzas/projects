/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	PapaXmasElf.hpp
*/

#pragma once

#include "IElf.hpp"
#include "Toy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"

class	PapaXmasElf : public IElf {
public:
	PapaXmasElf();
	~PapaXmasElf();

	ITable		*getTable() const override { return (p_table); };
	IConveyorBelt	*getConveyorBelt() const override { return (p_belt); };

	void		setTable(ITable *table) override;
	void		setConveyorBelt(IConveyorBelt *belt) override;

	bool		makeGift() override;
	void		makeAllGifts() override;

	void		sendGift(GiftPaper *gift);
	void		wrapToy(Toy *toy, Box *box);
	void		wrapBox(Box *box, GiftPaper *paper);

	bool		emptyConveyor();
	bool		pullNext();

	Toy		*searchToy();
	Box		*searchEmptyBox();
	Box		*searchFullBox();
	GiftPaper	*searchEmptyGiftPaper();
	GiftPaper	*searchFullGiftPaper();

private:
	ITable		*p_table;
	IConveyorBelt	*p_belt;
};
