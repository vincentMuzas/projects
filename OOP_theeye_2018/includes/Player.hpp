/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Player
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

#include "Object.hpp"

class Player : public Object {
	public:
		Player(sf::Texture &texture, std::string &msg, int sizeX, int sizeY);
		virtual void display(sf::RenderWindow &window, float zoom) override;
		int Inventory[7];
		int id;
		int orientation;
		int level;
		int caseX;
		int caseY;
		std::string team;
};

#endif /* !PLAYER_HPP_ */
