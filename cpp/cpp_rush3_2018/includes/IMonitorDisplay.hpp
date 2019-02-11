/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
	#define IMONITORDISPLAY_HPP_

#include "IMonitorModule.hpp"

class IMonitorDisplay {
	public:
		virtual void Display() noexcept = 0;

	protected:
		enum Order
		{
			DATE,
			OS,
			NAME,
			CPU,
			RAM
		};

		std::vector<IMonitorModule *> _modules;
		std::vector<Order> _order;
};

#endif /* !IMONITORDISPLAY_HPP_ */
