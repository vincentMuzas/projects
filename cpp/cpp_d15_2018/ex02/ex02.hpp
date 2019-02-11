/*
** EPITECH PROJECT, 2018
** ex02
** File description:
** 
*/

#pragma once

#include <string>
#include <iostream>

template <typename type>
type min(const type a, const type b)
{
	std::cout << "template min" << std::endl;
	return (a <= b) ? a : b;
}

template <>
int min<int>(const int a, const int b)
{
	std::cout << "non-template min" << std::endl;
	return (a <= b) ? a : b;
}

template <typename type>
type templateMin(const type *array, const int size)
{
	type smallest = array[0];
	for (int i = 1; i < size; i++)
		smallest = min(array[i], smallest);
	return smallest;
}

int nonTemplateMin(const int *arr, const int size)
{
	int smallest = arr[0];
	for (int i = 1; i < size; i++)
		smallest = min(arr[i], smallest);
	return smallest;
}
