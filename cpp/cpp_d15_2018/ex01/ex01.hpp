/*
** EPITECH PROJECT, 2018
** ex01
** File description:
** 
*/

#pragma once

template <typename type>
int compare(const type a, const type b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
}
