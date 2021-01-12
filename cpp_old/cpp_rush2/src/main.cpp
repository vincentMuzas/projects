/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	main.cpp
*/

#include "../includes/PapaXmasElf.hpp"
#include "../includes/Tests.hpp"
#include "../includes/ConveyorBeltRand.hpp"
#include "../includes/TableRand.hpp"

int	main()
{
	std::cout << "====== Welcome to the Santa Klauas chain packaging "
			<< "simulator ======" << std::endl << std::endl;

	Tests::RunTests();

	std::cout << std::endl;
	std::cout << " --- Make an elf working ! ---" << std::endl;

	IElf	*elf = new PapaXmasElf();

	elf->makeAllGifts();

	delete elf;

	std::cout << std::endl;
	std::cout << " --- Make a second elf working ! ---" << std::endl;

	elf = new PapaXmasElf();

	elf->setConveyorBelt(new ConveyorBeltRand());
	elf->setTable(new TableRand());

	elf->makeAllGifts();

	delete elf;

	std::cout << std::endl;
	std::cout << "====== Bye bye ! ======" << std::endl;

	return (0);
}
