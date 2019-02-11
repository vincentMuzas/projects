/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** main
*/

#include <iostream>
#include <fstream>

int main(int av, char **ac)
{
	std::ifstream fs;
	char error[] = "No such file or directory\n";
	int i = 1;

	if (av == 1)
		std::cerr << "my_cat: Usage: " << ac[0] << " file [...]\n";
	while (i < av) {
		fs.open(ac[i]);
		if (fs.is_open()) {
			std::cout << fs.rdbuf();
			fs.close();
		} else
			std::cerr << "my_cat: " << ac[i] << ": " << error;
		i++;
	}
	return 0;
}
