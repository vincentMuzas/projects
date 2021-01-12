/*
** EPITECH PROJECT, 2018
** temp
** File description:
**
*/

#include <iostream>
#include <iomanip>

int main(void)
{
	float nbr;
	std::string unit;

	std::cin >> nbr >> unit;
	std::cout << std::setprecision(3) << std::fixed;
	if (unit == "Celsius") {
		nbr = nbr * 9 / 5 + 32;
		std::cout << std::setw(16) << nbr;
		std::cout << std::setw(16) << "Fahrenheit" << std::endl;
	}
	if (unit == "Fahrenheit") {
		nbr = (nbr - 32) * 5 / 9;
		std::cout << std::setw(16) << nbr;
		std::cout << std::setw(16) << "Celsius" << std::endl;
	}
	return 1;
}
