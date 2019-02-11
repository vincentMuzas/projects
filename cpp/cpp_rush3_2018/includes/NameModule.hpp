/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** NameModule
*/

#ifndef NAMEMODULE_HPP_
	#define NAMEMODULE_HPP_

#include "IMonitorModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class NameModule : public IMonitorModule {
	public:
		NameModule();
		~NameModule();
		void refresh();
		std::vector<void *> getData();
		std::vector<int> getTypes();
	protected:
	private:
};

#endif /* !NAMEMODULE_HPP_ */
