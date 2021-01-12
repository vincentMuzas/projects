/*
** EPITECH PROJECT, 2018
** ex04.cpp
** File description:
** 
*/

#include "ex04.hpp"
#include <iostream>

template <typename type>
bool Tester<type>::equal(const type a, const type b) const
{
	if (a == b)
		return true;
	else
		return false;
}
