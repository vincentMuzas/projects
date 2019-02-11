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
	        cpy = plainchar + this->index;
		while ((plainchar >= 'a' && cpy > 'z') ||
		    (plainchar <= 'Z' && cpy > 'Z'))
			cpy = cpy - 26;
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
		cpy = cipherchar - this->index;
		while ((cipherchar >= 'a' && cpy < 'a') ||
		    (cipherchar <= 'Z' && cpy < 'A'))
			cpy = cpy + 26;
		cipherchar = cpy;
	}
	this->index++;
	std::cout << cipherchar;
}

void Cesar::reset()
{
	this->index = 3;
}
