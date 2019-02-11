/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Case
*/

#include "Case.hpp"

Case::Case(sf::Texture &texture, int x, int y) : Object(texture, x, y)
{
	for (size_t i = 0; i < 7; i++) {
		this->resource[i] = 0;
	}
	textureResource.loadFromFile("ressources.png");
	spriteResource.setTexture(textureResource);
	spriteResource.setScale(sf::Vector2f(
		float(textureX) / float(textureResource.getSize().x), 
		float(textureY) / float(textureResource.getSize().y)));
	font.loadFromFile("trebuchet_ms.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(texture.getSize().x * sprite.getScale().x / 6);
	text.setOutlineThickness(2);
	text.setOutlineColor(sf::Color::Black);
}

void Case::display(sf::RenderWindow &window, float zoom)
{
	this->sprite.setPosition(pos.x * textureX, pos.y * textureY);
	window.draw(this->sprite);
	sf::Rect<int> rect;
	for (size_t i = 0; i < 7; i++) {
		if (this->resource[i] > 0) {
			rect.top = int(i / 3) * (textureResource.getSize().y / 3);
			rect.left = (i % 3) * (textureResource.getSize().x / 3);
			rect.width = textureResource.getSize().x / 3;
			rect.height = textureResource.getSize().y / 3;
			spriteResource.setTextureRect(rect);
			spriteResource.setPosition(	pos.x * textureX + ((i % 3) * textureY / 3) ,
							pos.y * textureY + ((i / 3) * textureX / 3));
			window.draw(spriteResource);
			if (zoom < 0.5) {
				text.setString(std::to_string(resource[i]));
				text.setPosition(spriteResource.getPosition());
				window.draw(text);
			}
		}
	}
}