//
// EPITECH PROJECT, 2018
// SickKoala.hpp
// File description:
// 
//

#ifndef SICKKOALA_HPP_
# define SICKKOALA_HPP_

# include <string>
# include <iostream>
# include <algorithm>


class SickKoala
{
public:
	SickKoala(std::string str);
	~SickKoala();
	void poke();
	bool takeDrug(std::string str);
	void overDrive(std::string str);
private:
	std::string name;
};

#endif /* !SICKKOALA_HPP_ */
