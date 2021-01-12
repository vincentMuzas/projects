/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
** 	tests.cpp
*/

#include "../includes/Tests.hpp"

Object	**Tests::MyUnitTests()
{
	Object	**result = new Object*[2];
	result[0] = new LittlePony("happy pony");
	result[1] = new Teddy("cuddles");
	return (result);
}

Object	*Tests::MyUnitTests(Object **content)
{
	if (content == nullptr && content[0] != nullptr) {
		std::cerr << "MyUnitTests(Object **): Error, parameter is null"
			  << " or empty!" << std::endl;
		return (nullptr);
	}
	Toy		*toy = static_cast<Toy *>(content[0]);
	Box		*box = static_cast<Box *>(content[1]);
	GiftPaper	*gp = static_cast<GiftPaper *>(content[2]);
	if (toy == nullptr || box == nullptr || gp == nullptr) {
		std::cerr << "MyUnitTests(Object **): Error, null object given"
			  << " as parameter !" << std::endl;
		return (nullptr);
	}
	box->openMe();
	box->wrapMeThat(toy);
	box->closeMe();
	gp->wrapMeThat(box);
	return (gp);
}

void	Tests::RunTests()
{
	std::cout << " -- Unit tests --" << std::endl;

	Object	**result = Tests::MyUnitTests();
	if (result != nullptr) {
		std::cout << "Happy pony test : title == "
			  << result[0]->getTitle() << "; type == "
			  << result[0]->getTypeName() << std::endl;
		std::cout << "Cuddles test : title == "
			  << result[1]->getTitle() << "; type == "
			  << result[1]->getTypeName() << std::endl;
	}
	delete result[0];
	delete result[1];
	delete [] result;
	std::cout << std::endl;

	Object	*content[4];
	content[0] = new Teddy("A simple bear");
	content[1] = new Box("Plastic box");
	content[2] = new GiftPaper("Strange Paper");
	content[3] = nullptr;

	Object	*result2 = Tests::MyUnitTests(content);

	Wrap	*w = dynamic_cast<Wrap *>(result2);
	std::cout << "Some " << w->getTitle() << " under the tree..."
		  << std::endl;
	Wrap	*b = dynamic_cast<Wrap *>(w->getObj());
	std::cout << "And a " << b->getTitle() << " inside..."
			<< std::endl;
	std::cout << b->getObj()->getTitle() << " from my grand-pa ! GREAT !"
		  << std::endl;

	delete content[2];

	std::cout << " --- END OF UNIT TESTS ---" << std::endl;
}
