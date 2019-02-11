/*
** EPITECH PROJECT, 2018
** OneTime.hpp
** File description:
** 
*/

#pragma once

#include <iostream>
#include <string>
#include "IEncryptionMethod.hpp"
// std::string data = "Abc";
// std::transform(data.begin(), data.end(), data.begin(), ::tolower);

char tolower(char in);

class OneTime : public IEncryptionMethod
{
public:
	OneTime(const std::string &key);
        void encryptChar(char plainchar);
	void decryptChar(char cipherchar);
        void reset();
private:
	unsigned int index;
	std::string initial_key;
	std::string true_key;
};
