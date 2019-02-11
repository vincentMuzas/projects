/*
** EPITECH PROJECT, 2018
** ex00
** File description:
** 
*/

#include <iostream>
#include <algorithm>
#include <vector>

template <typename type>
int do_find(type var, int thing)
{
	std::vector<int> t{thing};
	return std::find_first_of(var.begin(), var.end(), t.begin(), t.end);
}
