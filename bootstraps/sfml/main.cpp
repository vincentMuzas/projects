/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <vector>
#include <iostream>

int compareStrings(std::string s1, std::string s2)
{
	return (s1.compare(s2));
}

void Server(int port, sf::TcpSocket *sock)
{
	sf::TcpListener listener;
	listener.listen(port);
	listener.accept(*sock);
	std::cout << "client " << sock->getRemoteAddress() << std::endl;
}

bool Client(int port, std::string ip, sf::TcpSocket *sock)
{
	if (sock->connect(ip, port) == sf::Socket::Done) {
		std::cout << "connected to " << sock->getRemoteAddress() << std::endl;
		return (true);
	}
	std::cout << "connection failed" << std::endl;
	return (false);
}

int main(int argc, char **argv)
{
	sf::TcpSocket socket;

	if (argc != 3)
		return (84);

	int port = atoi(argv[1]);
	if (!compareStrings("server", argv[2]))
		Server(port, &socket);
	else if (Client(port, argv[2], &socket) == false) {
		return (84);
	}

	socket.setBlocking(false);
	sf::SocketSelector selector;
	selector.add(socket);
	sf::Packet send;
	std::size_t received;

	sf::RenderWindow window(sf::VideoMode(800, 600), "window");
	window.setFramerateLimit(60);
	std::vector<const sf::CircleShape *> vectortab;
	sf::Event event;
	sf::Vector2i mousepos;
	sf::Vector2f mouseposf;
	sf::CircleShape *newcircle;
	int data[2];
	while (window.isOpen()) {
		window.clear();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus()) {
			mousepos = sf::Mouse::getPosition(window);
			newcircle = new sf::CircleShape();
			newcircle->setFillColor(sf::Color::Red);
			newcircle->setRadius(20);
			mouseposf.x =  mousepos.x - 20;
			mouseposf.y =  mousepos.y - 20;
			data[0] = mousepos.x;
			data[1] = mousepos.y;
			newcircle->setPosition(mouseposf);
			vectortab.push_back(newcircle);
			send.append(&data, sizeof(float) * 2);
			socket.send(send);
			send.clear();
		}

		if ((socket.receive(data, sizeof(float) * 2, received)) == sf::Socket::Done) {
			newcircle = new sf::CircleShape();
			newcircle->setFillColor(sf::Color::Red);
			newcircle->setRadius(20);
			mouseposf.x = data[0] - 20;
			mouseposf.y = data[1] - 20;
			newcircle->setPosition(mouseposf);
			vectortab.push_back(newcircle);
		}

		while (window.pollEvent(event)) {
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}
		for (int i = 0; i < vectortab.size(); i++) {
			window.draw(*vectortab[i]);
		}
		window.display();
	}
}