/*
** EPITECH PROJECT, 2018
** Picture.hpp
** File description:
**
*/

#ifndef PICTURE_HPP_
# define PICTURE_HPP_
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

class Picture
{
public:
	Picture(const std::string &file);
	~Picture();
	std::string data;
	bool getPictureFromFile(const std::string &file);
};

#endif
