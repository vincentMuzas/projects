/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Case
*/

#ifndef CASE_HPP_
	#define CASE_HPP_

#include <Object.hpp>

class Case : public Object {
	public:
		Case(sf::Texture &texture, int x, int y);
		virtual void display(sf::RenderWindow &window, float zoom) override;
		int resource[7];
	private:
		sf::Texture textureResource;
		sf::Sprite spriteResource;
		sf::Font font;
		sf::Text text;
};

#endif /* !CASE_HPP_ */
