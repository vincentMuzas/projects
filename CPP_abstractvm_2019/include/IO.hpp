/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** IO
*/

#pragma once

#include <iostream>
#include <list>
#include "Chipset.hpp"
#include "IComponents.hpp"
#include "IO.hpp"

#include <fstream>

class IO : IComponents
{
	public:
		IO();
		~IO();

        std::string getline();
        void run(std::ifstream &fd);
        void run();
        void stack_input(std::ifstream &fd);
        void stack_input();
        void say(std::string str);
        std::string sanitize_cin(std::string &cin);

    private:
        Chipset chip;
        std::list<std::string> call_stack;
};
