/*
** EPITECH PROJECT, 2018
** ex04.hpp
** File description:
** 
*/

#pragma once

template <typename type>
bool equal(const type a, const type b)
{
	return (a == b);
}

template <typename type>
class Tester {
public:
	Tester(){}
	~Tester(){}
	bool equal(const type a,const type b) const;
};
