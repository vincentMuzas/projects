/*
** EPITECH PROJECT, 2018
** 
** File description:
** cpp header file
*/

#ifndef MONITORMODULE_HPP_
# define MONITORMODULE_HPP_

# include "IMonitorModule.hpp"
# include <typeinfo>

class MonitorModule : public IMonitorModule {
public:
	MonitorModule(std::string mod, int value);
	MonitorModule(std::string mod, float value);
	MonitorModule(std::string mod, std::string value);
	~MonitorModule();
	int getIValue() const;
	float getFValue() const;
	std::string getSValue() const;
	std::string getModul() const;
private:
	std::string _mod;
	std::string _type;
	float _Fvalue;
	int _Ivalue;
	std::string _name;
};

#endif /* !MONITORMODULE_HPP_ */
