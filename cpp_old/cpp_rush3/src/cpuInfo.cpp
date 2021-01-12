/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** cpp file
*/

#include "../Include/cpuInfo.hpp"

std::vector<CPUData> *getCPUInfo()
{
	std::vector<CPUData> *entries = new std::vector<CPUData>;

	ReadStatsCPU(*entries);
	return entries;
}

void ReadStatsCPU(std::vector<CPUData> &entries)
{
	std::ifstream fileStat("/proc/stat");
	std::string line;
	const std::string str_cpu("cpu");
	const std::size_t len_scpu = str_cpu.size();
	const std::string tot("tot");

	while(std::getline(fileStat, line)) {
		if(!line.compare(0, len_scpu, str_cpu)) {
			std::istringstream ss(line);
			entries.emplace_back(CPUData());
			CPUData &entry = entries.back();
			ss >> entry.cpu;
			if(entry.cpu.size() > len_scpu)
				entry.cpu.erase(0, len_scpu);
			else
				entry.cpu = tot;
			for(int i = 0; i < 10; ++i)
				ss >> entry.times[i];
		}
	}
}

size_t GetOffTime(const CPUData &e)
{
	return	e.times[3] + e.times[4];
}

size_t GetActiveTime(const CPUData &e)
{
	return	e.times[0] + e.times[1] + e.times[2] + e.times[5] 
	+ e.times[6] + e.times[7] + e.times[8] + e.times[9];
}
