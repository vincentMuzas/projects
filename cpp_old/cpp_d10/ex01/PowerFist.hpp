/*
** EPITECH PROJECT, 2018
** PowerFist.hpp
** File description:
** 
*/

#ifndef POWERFIST_HPP_
# define POWERFIST_HPP_

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	~PowerFist();
	void attack() const override;
};

#endif
