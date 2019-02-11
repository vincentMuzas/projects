/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
	#define FEDERATION_HPP_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg {
	class Ship;
}

namespace Federation {
	namespace Starfleet {
		class Captain {
			public:
				Captain(std::string name);
				std::string getName();
				int getAge();
				void setAge(int age);
			private:
				std::string _name;
				int _age;
		};
		class Ship {
			public:
				Ship(int length, int width,
					std::string name, short maxWarp,
					int torpedo = 0);
				Ship();
				void setupCore(WarpSystem::Core *Core);
				void checkCore();
				void promote(Starfleet::Captain *Captain);
				bool move(int warp, Destination d);
				bool move(int warp);
				bool move(Destination d);
				bool move();
				int getShield();
				void setShield(int shield);
				int getTorpedo();
				void setTorpedo(int torpedo);
				void fire(Borg::Ship *target);
				void fire(int torpedoes, Borg::Ship *target);
			private:
				int _length;
				int _width;
				std::string _name;
				short _maxWarp;
				WarpSystem::Core *_core;
				Captain *_captain;
				Destination _location;
				Destination _home;
				int _shield;
				int _protonTorpedo;
		};
		class Ensign {
			public:
				explicit Ensign(std::string name);
			private:
				std::string _name;
		};
	};
	class Ship {
		public:
			Ship(int length, int width, std::string name);
			void setupCore(WarpSystem::Core *Core);
			void checkCore();
			WarpSystem::Core *getCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
		private:
			int _length;
			int _width;
			std::string _name;
			short _maxWarp;
			WarpSystem::Core *_core;
			Destination _location;
			Destination _home;
	};
};

#endif /* !FEDERATION_HPP_ */
