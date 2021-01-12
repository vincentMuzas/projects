/*
** EPITECH PROJECT, 2018
** TableRand.hpp
** File description:
**
*/

#pragma once

#include "PapaXmasTable.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "GiftDatas.hpp"
#include "Random.hpp"

class	TableRand : public PapaXmasTable {
public:
	TableRand();
	~TableRand();

private:
	Random	p_random;
};
