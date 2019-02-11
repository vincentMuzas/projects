/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	IElf.hpp
*/

#pragma once

#include "ITable.hpp"
#include "IConveyorBelt.hpp"

class	IElf {
public:
	virtual	~IElf() {};

	virtual ITable		*getTable() const = 0;
	virtual IConveyorBelt	*getConveyorBelt() const = 0;
	virtual void		setTable(ITable *table) = 0;
	virtual void		setConveyorBelt(IConveyorBelt *belt) = 0;

	virtual bool	makeGift() = 0;
	virtual void	makeAllGifts() = 0;
};
