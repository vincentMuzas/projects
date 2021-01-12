/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** Chipset
*/

#pragma once

#include "IComponents.hpp"
#include "CPU.hpp"

#include <iostream>
#include <map>

class Chipset : IComponents {
	public:
		Chipset();
		~Chipset();
        void run();
        std::string communicate(std::string &str);

    private:
        CPU cpu;
        std::map<CPU::fnts, std::string> functions;
};