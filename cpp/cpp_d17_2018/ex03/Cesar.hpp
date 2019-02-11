/*
** EPITECH PROJECT, 2018
** Cesar.hpp
** File description:
** 
*/

#pragma once

#include "IEncryptionMethod.hpp"
#include <string>
#include <iostream>

class Cesar : public IEncryptionMethod
{
public:
	Cesar() {}
	void reset();
	void encryptChar(char plainchar);
	void decryptChar(char cipherchar);
private:
	int index;
};
