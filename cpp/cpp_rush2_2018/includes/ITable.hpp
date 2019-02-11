/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	ITable.hpp
*/

#pragma once

#include "IContainer.hpp"

///
/// @brief An Elf table, used to make gifts.
///
/// Represents an elf's table that can be used to store Objects.
///
class	ITable : public IContainer {
public:
	virtual	~ITable() {};

	///
	/// @brief Take a look at this table content.
	///
	/// Gets titles of all {@link Object} present on this table.
	///
	/// @return Returns a null-terminated array of all objects titles
	/// 	on this table.
	///
	virtual std::string	**look() const = 0;

	virtual ITable	&operator<<(Object *obj) = 0;
	virtual ITable	&operator>>(Object *obj) = 0;
	virtual ITable	&operator+=(Object *obj) = 0;
	virtual ITable	&operator-=(Object *obj) = 0;
	virtual Object	*operator[](ssize_t idx) const = 0;
};
