/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** cpp header file
*/

#ifndef IMONITORMODULE_HPP_
	#define IMONITORMODULE_HPP_

#include <iostream>

class IMonitorModule {
public:
	virtual ~IMonitorModule() {}
	virtual std::string getModul() const = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
