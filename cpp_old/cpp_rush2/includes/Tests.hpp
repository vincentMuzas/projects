/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	Tests.hpp
*/

#pragma once

#include "../includes/Object.hpp"
#include "../includes/Toy.hpp"
#include "../includes/Teddy.hpp"
#include "../includes/LittlePony.hpp"

#include "../includes/IContainer.hpp"
#include "../includes/IConveyorBelt.hpp"
#include "../includes/PapaXmasConveyorBelt.hpp"
#include "../includes/ITable.hpp"
#include "../includes/PapaXmasTable.hpp"
#include "../includes/Wrap.hpp"
#include "../includes/Box.hpp"
#include "../includes/GiftPaper.hpp"

class	Tests {
public:
	static Object	**MyUnitTests();
	static Object	*MyUnitTests(Object **content);
	static void	RunTests();

};
