/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Observer
*/

#ifndef OBSERVER_HPP_
	#define OBSERVER_HPP_

#include <string>
#include <iostream>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <exception>

#include <SFML/Graphics.hpp>

#include "Socket.hpp"
#include "Case.hpp"
#include "Player.hpp"

class Observer {
	public:
		Observer(const char ip[], const char port[]);
		~Observer();
		void run();
		void parse(std::string &msg);
		void windowLoop();
	protected:
	private:
		sf::RenderWindow window;
		const std::string ip;
		const int port;
		Socket sock;
		int connected;
		int x;
		int y;
		bool hasEnded;
		sf::Texture groundTexture;
		sf::Texture droneTexture;
		float zoom;
		float rotation;
		std::vector<Case *> plateau;
		std::vector<Player *> players;
};

#endif /* !OBSERVER_HPP_ */
