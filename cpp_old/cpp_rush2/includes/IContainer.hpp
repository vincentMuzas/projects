/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	Interface Container (for Tables & ConveyorBelt)
*/

#pragma once

#include "Object.hpp"

///
/// @brief An {@link Object} container interface.
///
/// Represent either a Table or a ConveyorBelt that contains one or more
/// 	{@link Object object(s)}
///
class	IContainer {
public:
	virtual	~IContainer() {};

	///
	/// @brief Gets the empty status of this container.
	///
	/// @return Returns `true` if this container is empty,
	/// 	`false` otherwise.
	///
	virtual bool	isEmpty() const = 0;

	///
	/// @brief Gets the full status of this container.
	///
	/// @return Returns `true` if this container is full,
	/// 	`false` otherwise.
	///
	virtual bool	isFull() const = 0;

	///
	/// @brief Returns the first {@link Object} with the given type.
	///
	/// @return Returns the first {@link Object} of the given type,
	/// 	`nullptr` otherwise.
	///
	virtual Object	*getFirstOfType(Object::ObjectType type) const = 0;

	///
	/// @brief Returns the first non-empty slot content.
	///
	/// @return Returns the {@link Object} in the first non-empty slot,
	/// 	`nullptr` otherwise.
	///
	virtual Object	*getFirst() const = 0;

	///
	/// @brief Returns the content of the given slot id.
	///
	/// @param slot The slot index where to search for.
	/// @return Returns the {@link Object} in the given slot if present,
	/// 	`nullptr` otherwise.
	///
	virtual Object	*getSlot(ssize_t slot) const = 0;

	///
	/// @brief Gets the number of available slots.
	///
	/// @return Returns the number of empty slots.
	///
	virtual size_t	emptySlots() const = 0;

	///
	/// @brief Checks whenever the given slot is empty.
	///
	/// @param slot The slot index to check for.
	/// @return Returns `true` if the slot is empty.
	///
	virtual bool	isEmpty(ssize_t slot) const = 0;

	///
	/// @brief Check whenever the given object is present in this container.
	///
	/// @param obj The {@link Object} to check.
	/// @return Returns `true` if the object is in this container
	/// 	`false` otherwise.
	///
	virtual bool	contains(Object *obj) const = 0;

	///
	/// @brief Gets the max number of available slots.
	///
	/// @return Returns the max number of slots.
	///
	virtual size_t	maxSlots() const = 0;

	///
	/// @brief Add an Object to this container
	///
	/// Adds the given object to the first available slot
	/// and returns the slot's id.
	///
	/// @param obj The {@link Object} to add.
	/// @return Returns the obj's slot id, or (-1) if not slot is available
	///
	virtual	ssize_t	add(Object *obj) = 0;

	///
	/// @brief Set an {@link Object} in the given slot.
	///
	/// if idx is inferior to 0, the index starts from the end.
	///
	/// @param idx The index where the object should be inserted.
	/// @param obj The {@link Object} to add.
	/// @return Returns `true` if the object was successfully inserted
	/// 	`false` otherwise.
	///
	virtual bool	set(ssize_t idx, Object *obj) = 0;

	///
	/// @brief Remove the object in the given slot.
	///
	/// if idx is inferior to 0, the index starts from the end.
	///
	/// @param idx The index where the object should be removed from.
	/// @return Returns `true` if the object was successfully removed
	/// 	`false` otherwise.
	///
	virtual bool	remove(ssize_t idx) = 0;

	///
	/// @brief Remove the given object from this container.
	///
	/// @param obj The {@link Object} to remove.
	/// @return Returns `true` if the object was successfully removed
	/// 	`false` otherwise.
	///
	virtual bool	remove(Object *obj) = 0;
};
