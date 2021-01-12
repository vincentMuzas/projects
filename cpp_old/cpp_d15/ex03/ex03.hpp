/*
** EPITECH PROJECT, 2018
** ex03
** File description:
** 
*/

#pragma once

#include <iostream>

template <typename type>
void foreach(type *tab, void (*funcptr)(const type &elem), int size)
{
	for (int i = 0; i < size; i++)
		funcptr(tab[i]);
}

template <typename type>
void print(const type &elem)
{
	std::cout << elem << std::endl;
}
