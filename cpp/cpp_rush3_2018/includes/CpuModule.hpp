/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** CpuModule
*/

#ifndef CPUMODULE_HPP_
	#define CPUMODULE_HPP_

#include "IMonitorModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdio.h>

class CpuModule : public IMonitorModule {
	public:
		CpuModule();
		~CpuModule();
		void refresh();
		std::vector<void *> getData();
		std::vector<int> getTypes();
	protected:
	private:
};

#endif /* !CPUMODULE_HPP_ */
