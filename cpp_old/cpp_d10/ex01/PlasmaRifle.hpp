/*
** EPITECH PROJECT, 2018
** PlasmaRifle.hpp
** File description:
** 
*/

#ifndef PLASMARIFFLE_HPP_
# define PLASMARIFFLE_HPP_

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	~PlasmaRifle();
	void attack() const override;
};

#endif
