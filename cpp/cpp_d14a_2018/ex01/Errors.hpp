/*
** EPITECH PROJECT, 2018
** Errors.hpp
** File description:
**
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <iostream>
#include <exception>

class NasaError : public std::exception
{
public:
        NasaError(std::string const &message,
		  std::string const &component = "Unknown") noexcept;
	virtual ~NasaError() {}

        std::string const &getComponent() const;
	const char* what() const noexcept override;
protected:
        std::string const _message;
	std::string const _component;
};

class MissionCriticalError : public NasaError
{
public:
        MissionCriticalError(std::string const &message,
			     std::string const &component = "Unknown") noexcept;
};

class LifeCriticalError : public NasaError
{
public:
        LifeCriticalError(std::string const &message,
			  std::string const &component = "Unknown") noexcept;
};

class UserError : public NasaError
{
public:
        UserError(std::string const &message,
		  std::string const &component = "Unknown") noexcept;
};

class CommunicationError : public NasaError
{
public:
        CommunicationError(std::string const &message) noexcept;
};

#endif
