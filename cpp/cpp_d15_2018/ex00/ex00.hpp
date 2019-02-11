/*
** EPITECH PROJECT, 2018
** ex00
** File description:
** 
*/

#pragma once

template <typename type>
void swap(type &a, type &b)
{
	type cache;

	cache = a;
	a = b;
	b = cache;
}


template <typename type>
type min(const type a, const type b)
{
	return (a < b) ? a : b;
}

template <typename type>
type max(const type a, const type b)
{
	return (a > b) ? a : b;
}

template <typename type>
type add(const type a, const type b)
{
	return a + b;
}
