/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "Parser.hpp"
#include <cctype>

int division(int a, int b)
{
	return a / b;
}

int mult(int a, int b)
{
	return a * b;
}

int add(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

int modulo(int a , int b)
{
	return a % b;
}

Parser::Parser()
{
	this->reset();
}

void Parser::feed(const std::string &str)
{
	int nbr1, nbr2, i = 0;
	this->calc = str;
	while (str[i] != 0)
	{
		if (isdigit(str[i]))
			nbr1 = atoi(&str[i]);
		while (isdigit(str[i]))
		       i++;
		nbr2 = atoi(&str[i+1]);
		this->res += nbr1
	}
}

void Parser::reset()
{
	this->calc = "";
	this->res = 0;
}

int Parser::result() const
{
	return this->res;
}
