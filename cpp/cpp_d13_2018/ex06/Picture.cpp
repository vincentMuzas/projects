/*
** EPITECH PROJECT, 2018
** Picture.cpp
** File description:
** 
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
	this->getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file_o)
{
	std::ifstream file(file_o.c_str());
	std::stringstream buffer;
	if (file) {
		buffer << file.rdbuf();
		this->data = buffer.str();
		if (this->data == "")
			return false;
	}
	else {
		this->data = "ERROR";
	}
	return true;
}
