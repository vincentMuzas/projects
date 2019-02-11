/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(sf::Texture &texture, double x, double y)
{
	this->sprite.setTexture(texture);
	this->pos.x = x;
	this->pos.y = y;
	this->textureX = texture.getSize().x;
	this->textureY = texture.getSize().y;
	sprite.setPosition(pos);
}