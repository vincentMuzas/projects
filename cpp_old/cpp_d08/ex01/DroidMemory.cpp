/*
** EPITECH PROJECT, 2018
** DroidMemory.cpp
** File description:
**
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : FingerPrint(random()), Exp(0)
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerPrint()
{
	return this->FingerPrint;
}

size_t DroidMemory::getExp()
{
	return this->Exp;
}

void DroidMemory::setFingerPrint(size_t print)
{
	this->FingerPrint = print;
}

void DroidMemory::setExp(size_t exp)
{
	this->Exp = exp;
}

DroidMemory &DroidMemory::operator>>(size_t &value)
{
	value += this->Exp;
	return *this;
}

DroidMemory &DroidMemory::operator<<(size_t &value)
{
	this->Exp += value;
	return *this;
}
