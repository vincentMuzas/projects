/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
	#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist();
		~PowerFist();
		void attack() const override;
	protected:
	private:
};

#endif /* !POWERFIST_HPP_ */
