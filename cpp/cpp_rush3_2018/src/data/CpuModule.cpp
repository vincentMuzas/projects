/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** CpuModule
*/

#include "CpuModule.hpp"

CpuModule::CpuModule()
{
	this->types.push_back(this->END);
}

CpuModule::~CpuModule()
{
}

static std::string *getCpuUsage()
{
	long double a[4], b[4], loadavg;
	FILE *fp;
	std::string *biloute = new std::string();

	fp = fopen("/proc/stat","r");
	fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
	fclose(fp);
	sleep(1);

	fp = fopen("/proc/stat","r");
	fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
	fclose(fp);

	loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) /
		((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
	biloute->assign("CPU usage: " + std::to_string(loadavg * 100) + "%");
	return(biloute);
}

static std::string *getCpuCount()
{
	std::ifstream file("/proc/cpuinfo");
	std::string *name = new std::string("number of cpus: ");

	FILE *cmd = popen("grep '^processor' /proc/cpuinfo | wc -l", "r");
	if (cmd != NULL) {
			unsigned nprocs;
			size_t n;
			char buff[8];

			if ((n = fread(buff, 1, sizeof(buff)-1, cmd)) <= 0)
				return name;

			buff[n] = '\0';
			if (sscanf(buff, "%u", &nprocs) != 1)
				return name;

			name->append(buff);
			pclose(cmd);
	}
	return (name);
}

static std::string *getCpuName()
{
	std::ifstream file("/proc/cpuinfo");
	std::string *name = new std::string();

	FILE *cmd = popen("grep 'model name' /proc/cpuinfo | head -n 1", "r");
	if (cmd != NULL) {
			size_t n;
			char buff[128];

			if ((n = fread(buff, 1, sizeof(buff)-1, cmd)) <= 0)
				return name;

			buff[n] = '\0';

			name->assign(buff);
			pclose(cmd);
	}
	return (name);
}

void CpuModule::refresh()
{
	this->data.clear();
	this->types.clear();
	
	this->data.push_back(getCpuUsage());
	this->types.push_back(this->STRING);

	this->data.push_back(getCpuCount());
	this->types.push_back(this->STRING);

	this->data.push_back(getCpuName());
	this->types.push_back(this->STRING);

	this->types.push_back(this->END);
}

std::vector<void *> CpuModule::getData()
{
	return (data);
}

std::vector<int> CpuModule::getTypes()
{
	return (types);
}