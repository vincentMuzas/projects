/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(sf::Texture &texture, std::string &msg, int sizeX, int sizeY) : Object(texture, 0, 0)
{
	for (size_t i = 0; i < 7; i++) {
		this->Inventory[i] = 0;
	}
	sprite.setScale(sf::Vector2f(
		sizeX / float(texture.getSize().x),
		sizeY / float(texture.getSize().y)));
	sprite.setOrigin(sf::Vector2f(
		texture.getSize().x / 2,
		texture.getSize().y / 2));
	sscanf(msg.c_str(), "pnw %d %f %f %d %d", &id, &pos.x, &pos.y, &orientation, &level);
	caseX = sizeX;
	caseY = sizeY;
	font.loadFromFile("trebuchet_ms.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(texture.getSize().x * sprite.getScale().x / 2);
	text.setOutlineThickness(3);
	text.setOutlineColor(sf::Color::Black);
}

void Player::display(sf::RenderWindow &window, float zoom)
{
	sf::Vector2f vec(
		pos.x * caseX + caseX / 2,
		pos.y * caseY + caseY / 2);
	sprite.setRotation((orientation - 1) * 90);
	sprite.setPosition(vec);
	window.draw(sprite);
	if (zoom < 1) {
		text.setString(std::to_string(this->level));
		text.setPosition(vec);
		window.draw(text);
	}
}