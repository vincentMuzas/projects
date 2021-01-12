/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	PapaXmasTable.cpp
*/

#include "../includes/PapaXmasTable.hpp"

#include "../includes/Box.hpp"
#include "../includes/GiftPaper.hpp"
#include "../includes/LittlePony.hpp"
#include "../includes/Teddy.hpp"

PapaXmasTable::PapaXmasTable() : p_size(10)
{
	this->p_content = new Object*[this->p_size];
	for (size_t i = 0; i < this->p_size; ++i) {
		this->p_content[i] = nullptr;
	}
}

PapaXmasTable::~PapaXmasTable()
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] != nullptr) {
			delete this->p_content[i];
		}
	}
	delete [] this->p_content;
}

PapaXmasTable	&PapaXmasTable::operator<<(Object *obj)
{
	this->add(obj);
	return (*this);
}

PapaXmasTable	&PapaXmasTable::operator>>(Object *obj)
{
	this->remove(obj);
	return (*this);
}

PapaXmasTable	&PapaXmasTable::operator+=(Object *obj)
{
	this->add(obj);
	return (*this);
}

PapaXmasTable	&PapaXmasTable::operator-=(Object *obj)
{
	this->remove(obj);
	return (*this);
}

Object	*PapaXmasTable::operator[](ssize_t idx) const
{
	ssize_t	index = (idx >= 0 ? idx : (this->p_size + idx));
	if (index < 0 || index >= (ssize_t)this->p_size) {
		return (nullptr);
	}
	return (this->p_content[index]);
}

bool	PapaXmasTable::isEmpty() const
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] != nullptr) {
			return false;
		}
	}
	return true;
}

bool	PapaXmasTable::isFull() const
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] == nullptr) {
			return false;
		}
	}
	return true;
}

Object	*PapaXmasTable::getFirst() const
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] != nullptr) {
			return (this->p_content[i]);
		}
	}
	return (nullptr);
}

Object	*PapaXmasTable::getFirstOfType(Object::ObjectType type) const
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] != nullptr
				&& this->p_content[i]->is(type)) {
			return (this->p_content[i]);
		}
	}
	return (nullptr);
}

Object	*PapaXmasTable::getSlot(ssize_t idx) const
{
	return (this->operator[](idx));
}

size_t	PapaXmasTable::emptySlots() const
{
	size_t	cnt = 0;
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] == nullptr) {
			cnt += 1;
		}
	}
	return (cnt);
}

bool	PapaXmasTable::contains(Object *obj) const
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] == obj) {
			return true;
		}
	}
	return false;
}

bool	PapaXmasTable::isEmpty(ssize_t idx) const
{
	ssize_t	index = (idx >= 0 ? idx : (this->p_size + idx));
	if (index < 0 || index >= (ssize_t)this->p_size) {
		return false;
	}
	return (this->p_content[index] == nullptr);
}

size_t	PapaXmasTable::maxSlots() const
{
	return (this->p_size);
}

std::string	**PapaXmasTable::look() const
{
	auto	size = (this->maxSlots() - this->emptySlots());
	std::string	**result = new std::string*[size + 1];
	size_t index = 0;
	for (size_t i = 0; i < this->p_size; ++i) {
		if (this->p_content[i] != nullptr) {
			result[index] = new std::string(
					this->p_content[i]->getTitle());
			index += 1;
		}
	}
	result[index] = nullptr;
	return result;
}

ssize_t	PapaXmasTable::add(Object *obj)
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] == nullptr) {
			this->p_content[i] = obj;
			return ((ssize_t) i);
		}
	}
	return (ssize_t) -1;
}

bool	PapaXmasTable::set(ssize_t idx, Object *obj)
{
	ssize_t	index = (idx >= 0 ? idx : (this->p_size + idx));
	if (index < 0 || index >= (ssize_t)this->p_size) {
		return false;
	}
	if (this->p_content[index] != nullptr) {
		return false;
	}
	this->p_content[index] = obj;
	return (true);
}

bool	PapaXmasTable::remove(ssize_t idx)
{
	ssize_t	index = (idx >= 0 ? idx : (this->p_size + idx));
	if (index < 0 || index >= (ssize_t)this->p_size) {
		return false;
	}
	if (this->p_content[index] != nullptr) {
		this->p_content[index] = nullptr;
		return true;
	}
	return false;
}

bool	PapaXmasTable::remove(Object *obj)
{
	for (size_t i = 0; i < this->p_size; i++) {
		if (this->p_content[i] == obj) {
			this->p_content[i] = nullptr;
			return true;
		}
	}
	return false;
}

ITable	*createTable()
{
	ITable *table = new PapaXmasTable();

	table->add(new GiftPaper());
	table->add(new Teddy("Bear"));
	table->add(new Box("Super Box"));
	table->add(new Box());
	table->add(new LittlePony());
	table->add(new Box("Not usable box :P"));

	return (table);
}
