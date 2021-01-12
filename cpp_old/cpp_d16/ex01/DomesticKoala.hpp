/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#pragma once

#include <vector>

using methodPointer_t = void (*ptr)(std::string &);
class DomesticKoala
{
public:
	DomesticKoala(KoalaAction &);
	~DomesticKoala();
	DomesticKoala(const DomesticKoala &);
	DomesticKoala &operator =(const DomesticKoala &);
	
private:
	const std::vector <methodPointer_t> *getActions() const;
	void learnAction(unsigned char command, methodPointer_t action);
	void unlearnAction(unsigned char command);
	void doAction(unsigned char command, const std:string &param);
	void setKoalaAction(KoalaAction &);
};

class KoalaAction
{
public:
	KoalaAction() = default;
	~KoalaAction() {};
};
