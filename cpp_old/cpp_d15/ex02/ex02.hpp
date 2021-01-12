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
type min(type a, type b)
{
	std::cout << "template min" << std::endl;
	return (a <= b) ? a : b;
}

template <>
int min<int>(int a, int b)
{
	std::cout << "non-template min" << std::endl;
	return (a <= b) ? a : b;
}

template <typename type>
type templateMin(type *array, int size)
{
	type smallest = array[0];
	for (int i = 1; i < size; i++)
		smallest = min(array[i], smallest);
	return smallest;
}

int nonTemplateMin(int *arr, int size)
{
	int smallest = arr[0];
	for (int i = 1; i < size; i++)
		smallest = min(arr[i], smallest);
	return smallest;
}
