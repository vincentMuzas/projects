/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** main
*/

#include "IO.hpp"
#include <iostream>
#include <fstream>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Factory.hpp"
#include "Int8.hpp"

int main(int argc, char const *argv[])
{
    IO io;
    std::ifstream file;

    if (argc >= 2) {
        file.open(argv[1]);
        if (file.is_open()) {
            try {
                io.run(file);
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
                std::exit(84);
            }
            file.close();
        }
        else {
            std::cerr << "cant open file" << std::endl;
            std::exit(84);
        }
    }
    else {
        try {
            io.run();
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            std::exit(84);
        }
        
    }
    return 0;
}
