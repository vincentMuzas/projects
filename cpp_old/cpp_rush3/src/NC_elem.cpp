/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** nc_elem
*/

#include "../Include/NC_display.hpp"

void	NC_display::DispDate()
{
	time_t now = time(0);
	tm *tmp = localtime(&now);
	mvprintw(5, 4, "Date: ");	
	mvprintw(5, 10, today(tmp->tm_wday));
	mvprintw(5, 15, tostr(tmp->tm_mday));
	mvprintw(5, 18, tomonth(tmp->tm_mon));
}

void	NC_display::DispCName()
{
	std::string str = " ";
	std::ifstream file("/proc/sys/kernel/hostname");
	getline(file, str);
	mvprintw(4, 4, "Name: ");
	mvprintw(4, 10, str.c_str());
}

void	NC_display::DispOs()
{
	std::string str = " ";
	std::ifstream file("/proc/sys/kernel/ostype");
	getline(file, str);
	mvprintw(1, 6, "OS: ");
	mvprintw(1, 10, str.c_str());
}

void	NC_display::DispOsVersion()
{
	std::string str = " ";
	std::ifstream file("/proc/sys/kernel/version");
	getline(file, str);
	mvprintw(2, 4, "Os V: ");
	mvprintw(2, 10, str.c_str());
}

void	NC_display::DispHour()
{
	time_t now = time(0);
	tm *tmp = localtime(&now);
	mvprintw(6, 4, "Time: ");
	mvprintw(6, 10, tostr(tmp->tm_hour));
	mvprintw(6, 13, ":");
	mvprintw(6, 15, tostr(tmp->tm_min));
	mvprintw(6, 18, ":");
	mvprintw(6, 20, tostr(tmp->tm_sec));
}

void	NC_display::DispCpu()
{
	unsigned int	i = _Contain.getIValue("nbcpu");
	int d = 7;
	int j = 0;

	for (size_t y = 0; i - 1 != y; y++) {
		mvprintw(d, 4, "CPU");
		mvprintw(d, 7, tostr(j));
		mvprintw(d, 8, ": ");
		j++;
		mvprintw(d, 10, std::to_string(_Contain.getFValue
		("cpu" + std::to_string(y))).c_str());
		mvprintw(d, 22, "%%");
		d = d + 1;
	}
	_Contain.getFValue("cpu1");
}

void	NC_display::DispRam()
{
	mvprintw(12, 4, "RAM: ");
	mvprintw(12, 10, std::to_string(_Contain.getFValue("ram")).c_str());
	mvprintw(12, 22, "%%");
	_Contain.getFValue("ram");
	_Contain.Refresh();
}