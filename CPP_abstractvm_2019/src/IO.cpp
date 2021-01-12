/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** IO
*/

#include "IO.hpp"
#include "Chipset.hpp"

IO::IO()
{
}

IO::~IO()
{
}

void IO::run(std::ifstream &fd)
{
    this->stack_input(fd);
    while (!this->call_stack.empty()) {
        this->say(this->chip.communicate(this->call_stack.front()));
        this->call_stack.pop_front();
    }
}

void IO::run()
{
    this->stack_input();
    while (!this->call_stack.empty()) {
        this->say(this->chip.communicate(this->call_stack.front()));
        this->call_stack.pop_front();
    }
}

void IO::stack_input(std::ifstream &fd)
{
    std::string cin;
    while (cin != ";;" && std::getline(fd, cin)) {
        if (cin == ";;")
            break;
        this->sanitize_cin(cin);
        this->call_stack.push_back(cin);
    }
}

void IO::stack_input()
{
    std::string cin;
    while (cin != ";;") {
        std::getline(std::cin, cin);
        if (cin == ";;")
            break;
        this->sanitize_cin(cin);
        this->call_stack.push_back(cin);
    }
}

std::string IO::sanitize_cin(std::string &cin)
{
    // comments
    int pos = cin.find_first_of(';');
    if (pos >= 0 ) {
        cin = cin.substr(0, pos);
    }
    // whitespaces
    for (std::size_t pos = 0; cin[pos] != 0; pos++) {
        if (cin[pos] == ' ' && cin[pos + 1] == ' ') {
            cin.erase(pos, 1);
            pos = 0;
        }
    }
    // start of line
    while (cin[0] == ' ') {
        cin.erase(0, 1);
    }
    return (cin);
}

void IO::say(std::string str)
{
    if (str.length())
        std::cout << str << std::endl;
}