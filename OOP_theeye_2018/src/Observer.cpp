/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Observer
*/

#include "Observer.hpp"

Observer::Observer(const char ip[], const char port[]): ip(ip), port(atoi(port)), sock(0), x(0), y(0), hasEnded(false)
{
	this->groundTexture.loadFromFile("ground.png");
	this->droneTexture.loadFromFile("drone.png");
	sockaddr_in sockin;
	inet_pton(AF_INET, this->ip.c_str(), &sockin.sin_addr.s_addr);
	sockin.sin_family = AF_INET;
	sockin.sin_port = htons(this->port);
	this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	
	connected = connect(this->sock.getfd(), (sockaddr *)&sockin, sizeof(sockin));
	zoom = 1;
	rotation = 0;
}

Observer::~Observer()
{
}

void Observer::parse(std::string &msg)
{
	if (msg.find("msz") != std::string::npos) {
		sscanf(msg.c_str(), "msz %d %d\n", &this->x, &this->y);
	}	
	else if (msg.find("bct") != std::string::npos) {
		auto elem = new Case(groundTexture, 0, 0);
		sscanf(msg.c_str(), "bct %f %f %d %d %d %d %d %d %d\n", &elem->pos.x, &elem->pos.y, &elem->resource[0], &elem->resource[1], &elem->resource[2], &elem->resource[3], &elem->resource[4], &elem->resource[5], &elem->resource[6]);
		for (size_t i = 0; i < this->plateau.size(); i++) {
			if (plateau[i]->pos.x == elem->pos.x && plateau[i]->pos.y == elem->pos.y) {
				plateau.erase(plateau.begin() + i);
			}
		}
		this->plateau.push_back(elem);
	}
	else if (msg.find("pnw") != std::string::npos) {
		auto elem = new Player(droneTexture, msg, groundTexture.getSize().x, groundTexture.getSize().y);
		this->players.push_back(elem);
	}
	else if (msg.find("pdi") != std::string::npos) {
		int deathid;
		sscanf(msg.c_str(), "pdi %d\n", &deathid);
		for (size_t i = 0; i < this->players.size(); i++) {
			if (this->players[i]->id == deathid)
				this->players.erase(this->players.begin() + i);
		}
	}
	else if (msg.find("ppo") != std::string::npos) {
		int id, nX, nY, nO;
		sscanf(msg.c_str(), "ppo %d %d %d %d\n", &id, &nX, &nY, &nO);
		for (size_t i = 0; i < this->players.size(); i++) {
			if (players[i]->id == id) {
				players[i]->pos.x = nX;
				players[i]->pos.y = nY;
				players[i]->orientation = nO;
				break;
			}
		}
	}
	else if (msg.find("plv") != std::string::npos) {
		int id, nlv;
		sscanf(msg.c_str(), "plv %d %d\n", &id, &nlv);
		for (size_t i = 0; i < this->players.size(); i++) {
			if (players[i]->id == id) {
				players[i]->level = nlv;
				break;
			}
		}
	}
/*	if (msg.find("tna") != std::string::npos) {
		sscanf(msg.c_str(), "tna %s/n", &this->N);
	}
	if (msg.find("pin" + this->n) != std::string::npos) {
		sscanf(msg.c_str(), "pin %d %d %d %d %d %d %d %d %d %d\n", &this->n, &this->x, &this->y, &this->q0, &this->q1, &this->q2, &this->q3, &this->q4, &this->q5, &this->q6);
	}*/
}

void Observer::windowLoop()
{
	sf::Event event;
	window.clear();

	for (size_t i = 0; i < this->plateau.size(); i++) {
		this->plateau[i]->display(this->window, zoom);
	}
	for (size_t i = 0; i < this->players.size(); i++) {
		this->players[i]->display(this->window, zoom);
	}
	sf::View view;
	sf::Mouse mouse;
	view.setSize(sf::Vector2f(window.getSize().x * zoom, window.getSize().y * zoom));
	view.setRotation(rotation);
	sf::Vector2i boardsize(groundTexture.getSize().x * this->x, groundTexture.getSize().y * this->y);
	sf::Vector2f center((mouse.getPosition(window).x * boardsize.x) / window.getSize().x, (mouse.getPosition(window).y * boardsize.y)/ window.getSize().y);
	view.setCenter(center);
	window.setView(view);
	window.display();
	while (window.pollEvent(event)) {
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Up)
					zoom -= 0.1;
				if (event.key.code == sf::Keyboard::Down)
					zoom += 0.1;
				if (event.key.code == sf::Keyboard::Right)
					rotation += 1;
				if (event.key.code == sf::Keyboard::Left)
					rotation -= 1;
				if (zoom < 0.1)
					zoom = 0.1;
				break;
			case sf::Event::Closed:
				window.close();
				this->hasEnded = true;
				break;
			default:
				break;
		}
	}
}

void Observer::run()
{
	std::string *message;
	if (connected == -1)
		return;
	sock.getNextLine();
	sock.sendString("GRAPHICAL\n");
	while (!hasEnded) {
		if (!sock.avilable()) {
			sock.sendString("msz\n");
			std::string msg;
			for (size_t i = 0; i < players.size(); i++) {
				msg = "ppo ";
				msg.append(std::to_string(players[i]->id));
				msg.append("\n");
				sock.sendString(msg);
				msg[1] = 'l';
				msg[2] = 'v';
				sock.sendString(msg);
			}
			sock.recvData();
		}
		if (this->x > 0 && this->y > 0 && !window.isOpen()) {
			window.create(sf::VideoMode(1000, 1000), "window");
			window.setFramerateLimit(30);
		}
		if (this->window.isOpen())
			windowLoop();
		while (sock.avilable()) {
			message = sock.getNextLine();
			parse(*message);
		}
	}
}