/*
** EPITECH PROJECT, 2018
** IConveyorBelt.hpp
** File description:
**
*/

#pragma once

#include "Object.hpp"
#include "IConveyorBelt.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

class	PapaXmasConveyorBelt : public IConveyorBelt
{
public:
	PapaXmasConveyorBelt();
	~PapaXmasConveyorBelt() override;

	bool    isEmpty() const override;
	bool    isFull() const override;
	bool    isEmpty(ssize_t idx) const override;
	bool    contains(Object *obj) const override;

	Object	*getFirst() const override;
	Object	*getFirstOfType(Object::ObjectType type) const override;
	Object  *getSlot(ssize_t slot) const override;

	size_t  emptySlots() const override;
	size_t  maxSlots() const override;

	ssize_t add(Object *obj) override;
	bool    set(ssize_t idx, Object *obj) override;
	bool    remove(ssize_t idx) override;
	bool    remove(Object *obj) override;

	bool	IN() override;

	bool	OUT() override;
private:
	Object **p_slot;
	ssize_t const p_maxSlot;
	bool	p_in;
	bool	usable;
};

IConveyorBelt	*createConveyorBelt();
