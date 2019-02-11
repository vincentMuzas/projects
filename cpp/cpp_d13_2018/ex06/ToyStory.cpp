/*
** EPITECH PROJECT, 2018
** ToyStory.cpp
** File description:
** 
*/

#include "ToyStory.hpp"
#include "Picture.hpp"

ToyStory::tellMeAStory::tellMeAStory(std::string file,
				     Toy toy1, bool (Toy::*func1)(std::string),
				     Toy toy2, bool (Toy::*func2)(std::string))
{
	std::string line;
	std::ifstream book(file);
	bool turn = false;
	Toy *toyPtr;
	bool (Toy::*funcptr)(std::string);
	if (book) {
		std::cout << toy1.getAscii() << std::endl;
		std::cout << toy2.getAscii() << std::endl;
		while (getline(book, line)) {
			if (turn) {
				funcptr = func2;
				toyPtr = &toy2;
			} else {
				funcptr = func1;
				toyPtr = &toy1;
			}
			if (!line.compare(0, 8, "picture:")) {
			        toyPtr->setAscii(&line[8]);
				std::cout << toyPtr->getAscii() << std::endl;
			} else
				(*toyPtr.*funcptr)(line);
			turn = !turn;
		}
		book.close();
	}
	else
		std::cout << "Bad Story" << std::endl;
}
