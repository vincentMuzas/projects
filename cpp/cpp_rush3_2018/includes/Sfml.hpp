/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Sfml
*/

#ifndef SFML_HPP_
	#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "IMonitorDisplay.hpp"
#include "OsModule.hpp"
#include "NameModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"
#include "MemoryModule.hpp"

class IMonitorDisplay;

class Sfml: public IMonitorDisplay {
	public:
		Sfml();
		~Sfml();
		void Display() noexcept;

	private:
		void drawIt(IMonitorModule *) noexcept;
		void handleEvent(sf::Event &) noexcept;
		void eventModifyModule() noexcept;
		void openOptionWindow() noexcept;
		int isHere(Order) noexcept;
		void handleEventOption(sf::Event &, sf::Text *, sf::Text &,
			bool &) noexcept;
		void knowWho(sf::Text *, sf::Text &, bool &) noexcept;

		sf::RenderWindow _window;
		sf::Text _option;
		sf::Font _fn;
		size_t _offset;
};

#endif /* !SFML_HPP_ */
