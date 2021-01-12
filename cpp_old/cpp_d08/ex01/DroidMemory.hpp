/*
** EPITECH PROJECT, 2018
** DroidMemory.hpp
** File description:
**
*/

#ifndef DROIDMEMORY_CPP_
# define DROIDMEMORY_CPP_

# include <iostream>
# include <string>
# include <algorithm>

class DroidMemory
{
public:
	DroidMemory();
	~DroidMemory();
	size_t getFingerPrint();
	size_t getExp();
	void setFingerPrint(size_t exp);
	void setExp(size_t exp);
	DroidMemory &operator<<(size_t &value);
	DroidMemory &operator>>(size_t &value);

private:
	size_t FingerPrint;
	size_t Exp;
};

# endif /* !DROIDMEMORY_CPP_ */
