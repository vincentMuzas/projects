/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** DateModule
*/

#ifndef DATEMODULE_HPP_
	#define DATEMODULE_HPP_

#include "IMonitorModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include <ctime>
#include <chrono>

class DateModule : public IMonitorModule {
	public:
		DateModule();
		~DateModule();
		void refresh();
		std::vector<void *> getData();
		std::vector<int> getTypes();
	protected:
	private:
};

#endif /* !DATEMODULE_HPP_ */
