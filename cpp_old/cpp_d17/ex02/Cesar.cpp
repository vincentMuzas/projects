/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "Cesar.hpp"

void Cesar::encryptChar(char plainchar)
{
	int cpy = plainchar;

	if ((plainchar >= 'a' && plainchar <= 'z') ||
	    (plainchar >= 'A' && plainchar <= 'Z')) {
	        cpy = plainchar + this->index % 26;
		if ((plainchar >= 'a' && cpy > 'z') ||
		    (plainchar <= 'Z' && cpy > 'Z'))
			plainchar = cpy - 26;
		else
			plainchar = cpy;
	}
	this->index++;
	std::cout << plainchar;
}

void Cesar::decryptChar(char cipherchar)
{
	int cpy = cipherchar;

	if ((cipherchar >= 'a' && cipherchar <= 'z') ||
	    (cipherchar >= 'A' && cipherchar <= 'Z')) {
		cpy = cipherchar - this->index % 26;
		if ((cipherchar >= 'a' && cpy < 'a') ||
		    (cipherchar <= 'Z' && cpy < 'A'))
			cipherchar = cpy + 26;
		else
			cipherchar = cpy;
	}
	this->index++;
	std::cout << cipherchar;
}

void Cesar::reset()
{
	this->index = 3;
}
