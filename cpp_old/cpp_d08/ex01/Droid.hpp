/*
** EPITECH PROJECT, 2018
** Droid.hpp
** File description:
**
*/

#ifndef DROID_HPP_
# define DROID_HPP_

# include <string>
# include <iostream>

class Droid
{
public:
	Droid(std::string serial);
	~Droid() {
		std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
	}
	std::string getId() const;
	std::string getStatus() const;
	 size_t getEnergy() const;
	size_t getAttack() const;
	size_t getThoughness() const;
	void setId(const std::string to_set);
	void setStatus(std::string *to_set);
	void setEnergy(const size_t to_set);
	Droid &operator=(const Droid &old);
	bool operator==(const Droid &lop);
	bool operator!=(const Droid &lop);
	Droid &operator<<(size_t &value);
private:
	std::string Id;
	const size_t Attack;
	const size_t Thoughness;
	size_t Energy;
	std::string *Status;
};

std::ostream &operator<<(std::ostream &s, Droid &droid);

#endif /* !DROID_HPP_ */
