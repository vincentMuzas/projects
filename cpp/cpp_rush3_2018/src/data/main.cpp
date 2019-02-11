/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** main
*/

#include "NameModule.hpp"
#include "IMonitorModule.hpp"
#include "OsModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"

#include <SFML/Graphics.hpp>

int main()
{
	IMonitorModule *name = new NameModule();
	sf::RenderWindow window(sf::VideoMode(200, 200), "benis");
	sf::Text text;
	std::string texte;
	sf::Font treb;

	treb.loadFromFile("trebuchet_ms.ttf");

	while (window.isOpen()) {
		name->refresh();
		window.clear();
		for (unsigned int i = 0; i < name->getTypes().size(); i++) {
		        sf::Event event;
			while (window.pollEvent(event))	{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (name->getTypes()[i] == name->END)
				continue;
			if (name->getTypes()[i] == name->STRING)
				texte = (*static_cast<std::string *>(name->getData()[i]));
			if (name->getTypes()[i] == name->INT)
				std::cout << *static_cast<int *>(name->getData()[i]) << std::endl;

			text.setPosition(0, 24 * i);

			text.setString(texte);
			text.setFont(treb);
			text.setFillColor(sf::Color::White);
			text.setCharacterSize(24);

			window.draw(text);
		}
		window.display();
	}
}