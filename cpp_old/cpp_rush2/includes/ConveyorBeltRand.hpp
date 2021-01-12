/*
** EPITECH PROJECT, 2018
** ConveyorBeltRand.hpp
** File description:
**
*/

#pragma once

#include "PapaXmasConveyorBelt.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "GiftDatas.hpp"
#include "Random.hpp"

class	ConveyorBeltRand : public PapaXmasConveyorBelt {
public:
	ConveyorBeltRand();
	~ConveyorBeltRand();

	bool	IN();
	bool	OUT();

private:
	Random		p_random;
	GiftDatas	p_datas;
};
