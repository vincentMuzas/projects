/*
** EPITECH PROJECT, 2018
** ConveyorBelt.cpp
** File description:
**
*/

#include "../includes/PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt() : p_maxSlot(1)
{
	this->p_slot = new Object*[this->p_maxSlot];
	for (ssize_t i = 0; i < this->p_maxSlot; ++i) {
		this->p_slot[i] = nullptr;
	}
	this->p_in = false;
	this->usable = true;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
	for (ssize_t i = 0; i < this->p_maxSlot; ++i) {
		if (this->p_slot[i] != nullptr) {
			delete this->p_slot[i];
		}
	}
	delete [] this->p_slot;
	this->p_slot = nullptr;
	this->usable = false;
}

bool	PapaXmasConveyorBelt::isEmpty() const
{
	ssize_t i = 0;

	while (i < this->p_maxSlot) {
		if (this->p_slot[i] != nullptr)
			return (false);
		i++;
	}
	return true;
}

bool	PapaXmasConveyorBelt::isFull() const
{
	ssize_t i = 0;

	while (i < this->p_maxSlot) {
		if (this->p_slot[i] == nullptr)
			return (false);
		i++;
	}
	return true;
}

bool	PapaXmasConveyorBelt::isEmpty(ssize_t idx) const
{
	ssize_t i = (idx >= 0 ? idx : (this->p_maxSlot + idx));
	if (i < 0 || i >= this->p_maxSlot) {
		return false;
	}
	return (this->p_slot[i] == nullptr);
}

bool	PapaXmasConveyorBelt::contains(Object *obj) const
{
	for (ssize_t i = 0; i < this->p_maxSlot; i++) {
		if (this->p_slot[i] == obj)
			return true;
	}
	return false;
}

Object	*PapaXmasConveyorBelt::getFirst() const
{
	for (ssize_t i = 0; i < this->p_maxSlot; i++) {
		if (this->p_slot[i] != nullptr) {
			return this->p_slot[i];
		}
	}
	return nullptr;
}

Object	*PapaXmasConveyorBelt::getFirstOfType(Object::ObjectType type) const
{
	for (ssize_t i = 0; i < this->p_maxSlot; i++) {
		if (this->p_slot[i] != nullptr
				&& this->p_slot[i]->is(type)) {
			return this->p_slot[i];
		}
	}
	return nullptr;
}

Object	*PapaXmasConveyorBelt::getSlot(ssize_t slot) const
{
	if (slot < 0 && this->p_maxSlot - slot >= 0)
		slot = this->p_maxSlot + slot;
	if (slot >= 0 && slot < this->p_maxSlot)
		return this->p_slot[slot];
	return nullptr;
}

size_t PapaXmasConveyorBelt::emptySlots() const
{
	int i = 0;
	size_t ret = 0;

	while (i < this->p_maxSlot) {
		if (this->p_slot[i] == nullptr)
			ret++;
		i++;
	}
	return ret;
}

size_t PapaXmasConveyorBelt::maxSlots() const
{
	return this->p_maxSlot;
}

ssize_t PapaXmasConveyorBelt::add(Object *obj)
{
	int i = 0;

	while (i < this->p_maxSlot) {
		if (this->p_slot[i] == nullptr) {
			this->p_slot[i] = obj;
			return i;
		}
		i++;
	}
	return -1;
}

bool PapaXmasConveyorBelt::set(ssize_t idx, Object *obj)
{
	if (idx < 0)
		idx = this->p_maxSlot + idx;
	if (idx < 0 || idx >= this->p_maxSlot)
		return false;
	if (this->p_slot[idx] != nullptr)
		return false;
	this->p_slot[idx] = obj;
	return true;
}

bool PapaXmasConveyorBelt::remove(ssize_t idx)
{
	if (idx < 0)
		idx = this->p_maxSlot + idx;
	if (idx < 0 || idx >= this->p_maxSlot)
		return false;
	if (this->p_slot[idx] == nullptr)
	    return false;
	this->p_slot[idx] = nullptr;
	return true;
}

bool PapaXmasConveyorBelt::remove(Object *obj)
{
	int i = 0;

	while (i < this->p_maxSlot) {
		if (obj == this->p_slot[i]) {
			this->p_slot[i] = nullptr;
			return true;
		}
		i++;
	}
	return false;
}

bool PapaXmasConveyorBelt::IN()
{
	if (this->usable == false) {
		std::cerr << ERROR_USABLE << std::endl;
		return false;
	}
	if (!this->isEmpty()) {
		std::cerr << ERROR_NOT_EMPTY << std::endl;
		return false;
	} else if (this->p_in) {
		this->set(0, new GiftPaper());
	} else {
		this->set(0, new Box());
	}
	this->p_in = !this->p_in;
	return true;
}

bool PapaXmasConveyorBelt::OUT()
{
	if (this->usable == false) {
		std::cerr << ERROR_USABLE << std::endl;
		return false;
	}
	if (this->isEmpty()) {
		std::cerr << ERROR_IS_EMPTY << std::endl;
		return false;
	} else {
		delete this->p_slot[0];
		return this->remove((ssize_t) 0);
	}
}

IConveyorBelt	*createConveyorBelt()
{
	return (new PapaXmasConveyorBelt());
}
