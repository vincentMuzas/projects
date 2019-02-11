/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Socket
*/

#include "Socket.hpp"

Socket::Socket(int sockfd) : sockfd(sockfd)
{
}

Socket::~Socket()
{
}

void Socket::recvData()
{
	char buffer[4096] = {0};
	while (read(this->sockfd, buffer, sizeof(buffer)) == 4096)
		this->buffer.append(buffer);
	this->buffer.append(buffer);
}


void Socket::sendString(std::string msg)
{
	size_t writed = 0;
	while (writed < msg.size())
		writed += write(this->sockfd, &msg.c_str()[writed], msg.size());
}

Socket &Socket::operator=(int *newsock)
{
	this->sockfd = *newsock;
	return (*this);
}

std::string *Socket::getNextLine()
{
	if (buffer.find("\n") == std::string::npos)
		recvData();
	size_t endpos = 0, copied;
	while (endpos < buffer.length() && buffer[endpos] != '\n')
		endpos ++;
	if (endpos < buffer.length())
		endpos++;
	char buf[endpos + 1];
	copied = this->buffer.copy(buf, endpos);
	buf[copied] = 0;
	std::string * to_ret = new std::string(buf);
	this->buffer.erase(this->buffer.begin(), this->buffer.begin() + endpos);
	return (to_ret);
}

int Socket::getfd()
{
	return (this->sockfd);
}

int Socket::avilable()
{
	return (this->buffer.length());
}