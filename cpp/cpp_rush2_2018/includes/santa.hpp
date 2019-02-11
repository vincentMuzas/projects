/*
** EPITECH PROJECT, 2018
** Santa Claus Santa
** File description:
**
*/

#ifndef _SANTA_HPP_
# define _SANTA_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string>	getPresentList(std::string presentXML);

bool	checkInfosTokenWrap(std::string token);
bool	checkInfosTokenPresent(std::string token);
bool	checkList(std::vector<std::string>  list);
void	displayInfos(std::string token);
void	openPresent(std::vector<std::string> list);

#endif 
