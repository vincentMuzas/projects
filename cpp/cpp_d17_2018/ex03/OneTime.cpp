/*
** EPITECH PROJECT, 2018
** OneTime.cpp
** File description:
** 
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key) : initial_key(key), true_key(key)
{
	index = 0;
}

char tolower(char in){
	if(in <= 'Z' && in >= 'A')
		return in-('Z'-'z');
	return in;
}

void OneTime::encryptChar(char plainchar)
{
	int cpy;

	if ((plainchar >= 'a' && plainchar <= 'z') ||
	    (plainchar >= 'A' && plainchar <= 'Z')) {
		cpy = plainchar + (tolower(true_key[index]) - 'a') % 26;
		if ((plainchar >= 'a' && cpy > 'z') ||
		    (plainchar <= 'Z' && cpy > 'Z'))
			plainchar = cpy - 26;
		else
			plainchar = cpy;
	}
	this->index++;
	if (this->index == this->true_key.length())
		this->index = 0;
	std::cout << plainchar;
}

void OneTime::decryptChar(char cipherchar)
{
	int cpy = cipherchar;

	if ((cipherchar >= 'a' && cipherchar <= 'z') ||
	    (cipherchar >= 'A' && cipherchar <= 'Z')) {
		cpy = cipherchar - (tolower(true_key[index]) - 'a') % 26;
		if ((cipherchar >= 'a' && cpy < 'a') ||
		    (cipherchar <= 'Z' && cpy < 'A'))
			cipherchar = cpy + 26;
		else
			cipherchar = cpy;
	}
	this->index++;
	if (this->index == this->true_key.length())
		this->index = 0;
	std::cout << cipherchar;
}

void OneTime::reset()
{
	index = 0;
}
