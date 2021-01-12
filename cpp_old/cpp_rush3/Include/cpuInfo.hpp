/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** cpp header file
*/

#ifndef CPUINFO_HPP_
	#define CPUINFO_HPP_

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

typedef struct CPUData
{
	std::string cpu;
	size_t times[10];
} CPUData;

std::vector<CPUData> *getCPUInfo();
void ReadStatsCPU(std::vector<CPUData> &entries);
size_t GetOffTime(const CPUData &e);
size_t GetActiveTime(const CPUData &e);

#endif /* !CPUINFO_HPP_ */
