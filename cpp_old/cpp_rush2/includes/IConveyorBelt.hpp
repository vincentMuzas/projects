/*
** EPITECH PROJECT, 2018
** IConveyorBelt.hpp
** File description:
**
*/

#pragma once

#include "Object.hpp"
#include "IContainer.hpp"

class	IConveyorBelt : public IContainer {
public:
	virtual ~IConveyorBelt() {};

	virtual bool	IN() = 0;
	virtual bool	OUT() = 0;
};
