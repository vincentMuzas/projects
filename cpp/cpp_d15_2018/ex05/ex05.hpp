/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#pragma once

#include <string>
#include <iostream>

template <typename type>
class array
{
public:
	array(unsigned int size = 1) : size(size) {
		arr = new type[1];
	}
	array(type source) : size(source.size) {
		arr = new type[source.size];
		for (unsigned int i = 0; i < source.size; i++)
			arr[i] = source.arr[i];
	}
	~array() {}
	void dump() {
		std::cout << "[";
		for (unsigned int i = 0; i < this->size; i++) {
			if (i > 0)
				std::cout << ", ";
			std::cout << this->arr[i] << std::endl;
		}
		std::cout << "]";
	}
private:
	type *arr;
	unsigned int size;
};
