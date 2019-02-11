/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** OsModule
*/

#ifndef OSMODULE_HPP_
	#define OSMODULE_HPP_

#include "IMonitorModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/utsname.h>

class OsModule : public IMonitorModule {
	public:
		OsModule();
		~OsModule();
		void refresh();
		std::vector<void *> getData();
		std::vector<int> getTypes();
	protected:
	private:
};

#endif /* !OSMODULE_HPP_ */
