/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
	#define IMONITORMODULE_HPP_

#include <vector>
#include <string>

class IMonitorModule {
	public:
		virtual void refresh() = 0;
		virtual std::vector<void *> getData() = 0;
		virtual std::vector<int> getTypes() = 0;
		enum dataType {
			END,
			STRING,
			INT,
			TAB
		};
	protected:
		std::vector<void *> data;
		std::vector<int> types;
	private:
};

#endif /* !IMONITORMODULE_HPP_ */
