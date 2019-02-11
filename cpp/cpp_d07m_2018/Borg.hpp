/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** Borg
*/

#ifndef BORG_HPP_
	#define BORG_HPP_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

namespace Federation {
	namespace Starfleet {
		class Ship;
	}
	class Ship;
}

namespace Borg {
	class Ship {
		public:
			Ship(int weaponFrequency = 20, short repair = 3);
			void setupCore(WarpSystem::Core *Core);
			void checkCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
			int getShield();
			void setShield(int shield);
			int getWeaponFrequency();
			void setWeaponFrequency(int frequency);
			short getRepair();
			void setRepair(short repair);
			void fire(Federation::Starfleet::Ship *target);
			void fire(Federation::Ship *target);
			void repair();
		private:
			int _side;
			short _maxWarp;
			int _shield;
			int _weaponFrequency;
			short _repair;
			WarpSystem::Core *_core;
			Destination _location;
			Destination _home;
	};
};

#endif /* !BORG_HPP_ */
