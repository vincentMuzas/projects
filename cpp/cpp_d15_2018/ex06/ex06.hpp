/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

template <typename type>
std::string convert(type t)
{
	return std::to_string(t);
}

std::string convert(std::string t)
{
	return t;
}

template <typename type>
std::string type_to_str(type t)
{
	std::string b_str = "";

	if (typeid(t) == typeid(int))
		b_str = "[int:" + convert(t) + "]";
	else if (typeid(t) == typeid(float))
		b_str = "[float:" + convert(t) + "f]";
	else if (typeid(t) == typeid(std::string))
		b_str = "[string:\"" + convert(t) + "\"]";
	else
		b_str = "[???]";
	return b_str;
}

template <typename type1, typename type2>
class Tuple
{
	std::string toString() {
		std::string a_str = type_to_str(a);
		std::string b_str = type_to_str(b);
		std::string ret = "[TUPLE " + a_str + " " + b_str + "]";
		return ret;
	}
	type1 a;
	type2 b;
};
