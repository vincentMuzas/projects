/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	PapaXmasTable.hpp
*/

#pragma once

#include "ITable.hpp"

class	PapaXmasTable : public ITable {
public:
	PapaXmasTable();
	~PapaXmasTable();

	PapaXmasTable(const PapaXmasTable &other) = delete;
	PapaXmasTable	&operator=(const PapaXmasTable &other) = delete;

	PapaXmasTable	&operator<<(Object *obj) override;
	PapaXmasTable	&operator>>(Object *obj) override;
	PapaXmasTable	&operator+=(Object *obj) override;
	PapaXmasTable	&operator-=(Object *obj) override;
	Object		*operator[](ssize_t idx) const override;

	bool	isFull() const override;
	bool	isEmpty() const override;
	bool	isEmpty(ssize_t idx) const override;
	bool	contains(Object *obj) const override;

	Object	*getFirst() const override;
	Object	*getFirstOfType(Object::ObjectType type) const override;
	Object	*getSlot(ssize_t idx) const override;
	size_t	emptySlots() const override;
	size_t	maxSlots() const override;

	std::string	**look() const override;

	ssize_t	add(Object *obj) override;
	bool	set(ssize_t idx, Object *obj) override;
	bool	remove(ssize_t idx) override;
	bool	remove(Object *obj) override;

private:
	const size_t	p_size;
	Object		**p_content;

};

ITable	*createTable();
