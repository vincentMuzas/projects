/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** MemoryModule
*/

#ifndef MEMORYMODULE_HPP_
	#define MEMORYMODULE_HPP_

#include "IMonitorModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class MemoryModule : public IMonitorModule {
	public:
		MemoryModule();
		~MemoryModule();
		void refresh();
		std::vector<void *> getData();
		std::vector<int> getTypes();
	protected:
	private:
};

#endif /* !MEMORYMODULE_HPP_ */
