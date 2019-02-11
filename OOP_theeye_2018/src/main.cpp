/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** main
*/

#include <string>
#include <iostream>
#include <arpa/inet.h>

#include "Observer.hpp"


bool check_args(int argc, char const *argv[])
{
	if (argc != 3)
		return (false);

	struct sockaddr_in sa;
	int result = inet_pton(AF_INET, argv[1], &(sa.sin_addr));
	const std::string port(argv[2]);
	std::string::const_iterator it = port.begin();
	while (it != port.end() && std::isdigit(*it))
		it++;
	return (result != 0 && !port.empty() && it == port.end());
}

void print_help(char const name[])
{
	std::cout << "USAGE: " << std::string(name) << " ip port" << std::endl;
}

int main(int argc, char const *argv[])
{
	if (!check_args(argc, argv)) {
		print_help(argv[0]);
		return (84);
	}
	//good
	Observer obs(argv[1], argv[2]);
	obs.run();
	return 0;
}
