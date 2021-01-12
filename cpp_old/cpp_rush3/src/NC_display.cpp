/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NC_disp
*/

#include "../Include/NC_display.hpp"

NC_display::NC_display()
	: _Contain(ModuleContainer())
{}

NC_display::~NC_display()
{}


const char *NC_display::today(int x)
{
	const char *day_list[] = {"Sun.", "Mon.", "Tue.",
	 "Wed.", "Thu.", "Fri.", "Sat."};
	const char *current_Day = day_list[x];
	return current_Day;
}

const char *NC_display::tomonth(int x)
{
	const char *month_list[] = {"Jan.", "Feb.", "Mar.",
	 "Apr.", "May.", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov", "Dec"};
	const char *current_Month = month_list[x];
	return current_Month;
}

const char *NC_display::tostr(int x)
{
	std::stringstream str;
	str << x;
	return str.str().c_str();
}

void	NC_display::DispCurses()
{
	while (1) {
		initscr();
		DispCName();
		DispDate();
		DispHour();
		DispCpu();
		DispRam();
		DispOs();
		DispOsVersion();
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		endwin();
	}
}