/*
** EPITECH PROJECT, 2018
** Errors.cpp
** File description:
** 
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &Message,
		     std::string const &component) noexcept : _message(Message),
	_component(component)
{
}

std::string const &NasaError::getComponent() const
{
	return this->_component;
}

const char *NasaError::what() const noexcept
{
	return this->_message.c_str();
}

MissionCriticalError::MissionCriticalError(std::string const &message,
					   std::string const &component)
noexcept : NasaError::NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message,

				     std::string const &component)
noexcept : NasaError::NasaError(message, component)
{
}

UserError::UserError(std::string const &message,
		     std::string const &component)
noexcept : NasaError::NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message)
noexcept : NasaError::NasaError(message, "CommunicationDevice")
{
}
