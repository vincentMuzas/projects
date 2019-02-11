/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
	#define SOCKET_HPP_

#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "Socket.hpp"

class Socket {
	public:
		Socket(int sockfd);
		~Socket();
		void recvData();
		void sendString(std::string msg);
		std::string *getNextLine();
		int avilable();
		int getfd();
		Socket &operator=(int *i);
	protected:
	private:
		std::string buffer;
		int sockfd;
};

#endif /* !SOCKET_HPP_ */
