/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NC_display.hpp
*/

#ifndef NC_DISPLAY_HPP_
	#define NC_DISPLAY_HPP_

#include "ModuleContainer.hpp"
#include <ncurses.h>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <iomanip>

class NC_display {
public:
	NC_display();
	~NC_display();
	void	DispCurses();
	void	DispDate();
	void	DispCName();
	void	DispHour();
	void	DispCpu();
	void	DispRam();
	void	DispOs();
	void	DispOsVersion();
	const char *today(int x);
	const char *tostr(int x);
	const char *tomonth(int x);
private:
	std::string _pcName;
	ModuleContainer _Contain;
};

#endif /* !NC_DISPLAY_HPP_ */
