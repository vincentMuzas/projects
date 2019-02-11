/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 
*/

#ifndef NANO_HPP_
	#define NANO_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

namespace  nts
{
	enum  Tristate {
		UNDEFINED = (-true),
		TRUE = true ,
		FALSE = false
	};
	class IComponent
	{
	public:
		virtual ~IComponent() = default;
	public:
		virtual nts::Tristate compute(std::size_t  pin = 1) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent &other,
					std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};
}

class shell {
	public:
		shell(std::string file);
		~shell();
		void to_parse(std::string line);
};

class strtab {
	public:
		strtab(std::string basic = "") : str(basic) {};
		~strtab() {};
		std::string *split_string();
		void clear();
		std::string getstr();
		void setstr(std::string str);
	private:
		std::string str;
};

#endif /* !NANO_HPP_ */
