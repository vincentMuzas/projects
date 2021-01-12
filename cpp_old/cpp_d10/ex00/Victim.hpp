/*
** EPITECH PROJECT, 2018
** Victim.hpp
** File description:
**
*/

#ifndef VICTIM_HPP_
# define VICTIM_HPP_


# include "Sorcerer.hpp"

class Victim
{
public:
	Victim(std::string);
	~Victim();
	virtual void getPolymorphed() const;
	std::string name;
};

std::ostream &operator<<(std::ostream &lop, Victim &rop);

#endif /* !VICTIM_HPP_ */
