/*
** EPITECH PROJECT, 2018
** 
** File description:
** cpp header file
*/

#ifndef MODULECONTAINER_HPP_
# define MODULECONTAINER_HPP_

# include "MonitorModule.hpp"
# include "cpuInfo.hpp"
# include <fstream>
# include <cstdlib>

class ModuleContainer {
public:
	ModuleContainer();
	~ModuleContainer();
	void getCPUPercent();
	void getRAM();
	void Refresh();
	void netWork_refresh();
	int getNetRead() const;
	int getNetWrite() const;
	int getIValue(const std::string &name) const;
	float getFValue(const std::string &name) const;
	void getCPUModelAndFrequency();
	std::string getSValue(const std::string &name) const;
private:
	int last_netRead;
	int last_netWrite;
	int netWrite;
	int netRead;
	std::vector<MonitorModule> _mod;
	std::vector<CPUData> *_tmp;
};

#endif /* !MODULECONTAINER_HPP_ */
