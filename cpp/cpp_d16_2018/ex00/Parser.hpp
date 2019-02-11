/*
** EPITECH PROJECT, 2018
** parser.hpp
** File description:
** 
*/

#pragma once

#include <iostream>
#include <string>
#include <list>

class Parser
{
public:
	Parser() { this->reset(); }
	~Parser() {};
	void feed(const std::string &);
	int result() const;
	void reset();
private:
	std::string calc;
	int res;
	std::stack<char> operators;
	std::stack<int (*func)(int, int)> operands;
}
