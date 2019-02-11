/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
	_fn.loadFromFile("trebuchet_ms.ttf");
	_option.setFont(_fn);
	_option.setString("OPTION");
	_option.setPosition(800 - (30 * 6), 400);
	_option.setFillColor(sf::Color::Blue);
	_modules.clear();
	_order.clear();
	_modules.push_back(new OsModule());
	_order.push_back(OS);
	_modules.push_back(new NameModule());
	_order.push_back(NAME);
	_modules.push_back(new DateModule());
	_order.push_back(DATE);
	_modules.push_back(new CpuModule());
	_order.push_back(CPU);
	_modules.push_back(new MemoryModule());
	_order.push_back(RAM);
	_offset = 0;
}

Sfml::~Sfml()
{
}

void Sfml::drawIt(IMonitorModule *mod) noexcept
{
	std::vector<void *>data = mod->getData();
	sf::Text tmp;

	for (auto it = data.begin(); it != data.end(); it++) {
		tmp = sf::Text(static_cast<std::string *>(*it)->c_str(), _fn);
		tmp.setPosition(0, _offset);
		_offset += tmp.getCharacterSize();
		_window.draw(tmp);
	}
}

int Sfml::isHere(Order orr) noexcept
{
	int ret = -1;

	for (auto it = _order.begin(); it != _order.end(); it++)
		if (*it == orr)
			ret = it - _order.begin();
	return ret;
}

void Sfml::knowWho(sf::Text *txts, sf::Text &cancel,
	bool &win) noexcept
{
	sf::Vector2f ms(static_cast<float>(sf::Mouse::getPosition(_window).x),
			static_cast<float>(sf::Mouse::getPosition(_window).y));

	if (cancel.getGlobalBounds().contains(ms))
		win = false;
	if (txts[0].getGlobalBounds().contains(ms))
	{
		if (isHere(OS) != -1) {
			_modules.erase(_modules.begin() + isHere(OS));
			_order.erase(_order.begin() + isHere(OS));
		} else {
			_order.push_back(OS);
			_modules.push_back(new OsModule());
		}
		win = false;
	} else if (txts[1].getGlobalBounds().contains(ms)) {
		if (isHere(NAME) != -1) {
			_modules.erase(_modules.begin() + isHere(NAME));
			_order.erase(_order.begin() + isHere(NAME));
		} else {
			_order.push_back(NAME);
			_modules.push_back(new NameModule());
		}
		win = false;
	}
	if (txts[2].getGlobalBounds().contains(ms)) {
		if (isHere(DATE) != -1) {
			_modules.erase(_modules.begin() + isHere(DATE));
			_order.erase(_order.begin() + isHere(DATE));
		} else {
			_order.push_back(DATE);
			_modules.push_back(new DateModule());
		}
		win = false;
	} else if (txts[3].getGlobalBounds().contains(ms)) {
		if (isHere(CPU) != -1) {
			_modules.erase(_modules.begin() + isHere(CPU));
			_order.erase(_order.begin() + isHere(CPU));
		} else {
			_order.push_back(CPU);
			_modules.push_back(new CpuModule());
		}
		win = false;
	}
	if (txts[4].getGlobalBounds().contains(ms)) {
		if (isHere(RAM) != -1) {
			_modules.erase(_modules.begin() + isHere(RAM));
			_order.erase(_order.begin() + isHere(RAM));
		} else {
			_order.push_back(RAM);
			_modules.push_back(new MemoryModule());
		}
		win = false;
	}
}

void Sfml::handleEventOption(sf::Event &ev, sf::Text *txts,
	sf::Text &cancel, bool &win) noexcept
{
	
	switch (ev.type)
	{
		case sf::Event::Closed:
			_window.close();
			win = false;
			break;
		case sf::Event::MouseButtonPressed:
			knowWho(txts, cancel, win);
			break;
		default:
			break;
	}
}

void Sfml::openOptionWindow() noexcept
{
	sf::Text txts[5] = { sf::Text(std::string("os: ") + ((isHere(OS) != -1)
		? "Retirer" : "Ajouter"), _fn), sf::Text(std::string("name: ") +
		((isHere(NAME) != -1) ? "Retirer" : "Ajouter"), _fn),
		sf::Text(std::string("date: ") + ((isHere(DATE) != -1) ?
		"Retirer" : "Ajouter"), _fn), sf::Text(std::string("cpu: ") +
		((isHere(CPU) != -1) ? "Retirer" : "Ajouter"), _fn),
		sf::Text(std::string("RAM: ") + ((isHere(RAM) != 1) ? "Retirer"
		: "Ajouter"), _fn) }, cancel("Retour", _fn);
	bool window = true;

	while (window)
	{
		sf::Event event;
		while (_window.pollEvent(event))
			handleEventOption(event, txts, cancel, window);
		_window.clear();
		for (auto i = 0, offset = 30; i < 5; i++, offset +=
				txts[i].getCharacterSize()) {
			txts[i].setPosition(0, offset);
			_window.draw(txts[i]);
		}
		_window.draw(cancel);
		_window.display();
	}
}

void Sfml::eventModifyModule() noexcept
{
	if (_option.getGlobalBounds().contains(
		sf::Vector2f(static_cast<float>
			(sf::Mouse::getPosition(_window).x),
			static_cast<float>(sf::Mouse::getPosition(_window).y))))
		openOptionWindow();
}

void Sfml::handleEvent(sf::Event &ev) noexcept
{
	switch (ev.type)
	{
	case sf::Event::Closed:
		_window.close();
		break;
	case sf::Event::MouseButtonPressed:
		eventModifyModule();
	default:
		break;
	}
}

void Sfml::Display() noexcept
{
	_window.create(sf::VideoMode(800, 600), "");
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
			handleEvent(event);
		_window.clear();
		_offset = 0;
		for (auto it = _modules.begin(); it != _modules.end(); it++) {
			(*it)->refresh();
			drawIt(*it);
		}
		_window.draw(_option);
		_window.display();
	}
}
