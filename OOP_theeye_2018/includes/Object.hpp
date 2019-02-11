/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Object
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Object {
	public:
		Object(sf::Texture &texture, double x, double y);
		virtual void display(sf::RenderWindow &window, float zoom) = 0;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f pos;
		int textureX;
		int textureY;
		sf::Text text;
		sf::Font font;
};

#endif /* !OBJECT_HPP_ */
