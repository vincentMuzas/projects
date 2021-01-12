//
// EPITECH PROJECT, 2018
// rush2
// File description:
// deserializes xml files imaging gifts
//

#include "../includes/santa.hpp"

std::vector<std::string>	getPresentList(std::string presentXML)
{      
	presentXML.erase(std::remove(presentXML.begin(), presentXML.end(),
			'\t'), presentXML.end());
	presentXML.erase(presentXML.begin(), presentXML.begin() + 1);

	std::vector<std::string>	list;
	std::string	part;

	for (int i = 0; i < 7; i++) {
		part = presentXML.substr(0, presentXML.find('>'));
		presentXML.erase(0, presentXML.find('>') + 2);
		if (part != "")
			list.push_back(part);
	}
	return (list);
}

bool	checkInfosTokenWrap(std::string token)
{
	int		i = 0;
	std::string	first = "";
	std::string	second = "";

	while (token.c_str()[i] != '=' && token.c_str()[i] != '\0') {
		first += token.c_str()[i];
		i++;
	}
	first += token.c_str()[i];
	if (first.compare("Wrap Type=") != 0)
		return (false);
	i = i + 2;
	while (token.c_str()[i] != '\"'&& token.c_str()[i] != '\0')
		i++;
	i++;
	while (token.c_str()[i] != '=' && token.c_str()[i] != '\0') {
		second += token.c_str()[i];
		i++;
	}
	second += token.c_str()[i];
	if (second.compare(" Title=") != 0)
		return (false);
	i = i + 2;
	while (token.c_str()[i] != '\"' && token.c_str()[i] != '\0')
		i++;
	if (!(token.c_str()[i] == '\"' && token.c_str()[i + 1] == '\0'))
		return (false);
	return (true);
}

bool	checkInfosTokenPresent(std::string token)
{
	int		i = 0;
	std::string	first = "";
	std::string	second = "";

	while (token.c_str()[i] != '=' && token.c_str()[i] != '\0') {
		first +=  token.c_str()[i];
		i++;
	}
	first += token.c_str()[i];
	if (first.compare("Toy Type=") != 0)
		return (false);
	i = i + 2;
	while (token.c_str()[i] != '\"'&& token.c_str()[i] != '\0')
		i++;
	i++;
	while (token.c_str()[i] != '=' && token.c_str()[i] != '\0') {
		second += token.c_str()[i];
		i++;
	}
	second += token.c_str()[i];
	if (second.compare(" Title=") != 0)
		return (false);
	i = i + 2;
	while (token.c_str()[i] != '\"' && token.c_str()[i] != '\0')
		i++;
	if (!(token.c_str()[i] == '\"' && token.c_str()[i + 1] == '/'
					&& token.c_str()[i + 2] == '\0'))
		return (false);
	return (true);
}

bool	checkList(std::vector<std::string> list)
{
	if (list.size() != 7) {
		std::cerr << "Santa: It seems that the present was not "
			  << "correctly wrapped (error:  Incorrect brackets "
			  << "number)" << std::endl;
		return (false);
	}
	if (list[0].compare("Gift MagicNumber=\"0xDEADBEEF\"") != 0) {
		std::cerr << "Santa: Something seems wrong with the gift's "
			  << "certificate (error, the magic number token is "
			  << "invalid)" << std::endl;
		return (false);
	}
	if (list[4].compare("/Wrap") != 0
			|| list[5].compare("/Wrap") != 0
			|| list[6].compare("/Gift") != 0) {
		std::cerr << "Santa: The bottom of the gift looks damaged "
			  << "(error, the closing XML tockens are invalid)"
			  << std::endl;
		return (false);
	}
	if (!checkInfosTokenWrap(list[1]) || !checkInfosTokenWrap(list[2])) {
		std::cerr << "Santa: One of the wraps looks invalid"
			  << " (error with the wraping XML tokens)"
			  << std::endl;
		return (false);
	}
	if (!checkInfosTokenPresent(list[3])) {
		std::cerr << "Santa: The toy in the gift looks damaged"
			  << " (error with the Toy XML token)" << std::endl;
		return (false);
	}
	return (true);
}

void	displayInfos(std::string token)
{
	int	i = 0;

	while (token[i] != '\"')
		i++;
	i++;
	while (token[i] != '\"') {
		std::cout << token[i];
		i++;
	}
	i++;
	while (token[i] != '\"')
		i++;
	i++;
	std::cout << " of title \"";
	while (token[i] != '\"') {
		std::cout << token[i];
		i++;
	}
	std::cout << "\"";
}

void	openPresent(std::vector<std::string> list)
{
	std::cout << "Toy: I am a ";
	displayInfos(list[3]) ;
	std::cout << " and was packed in a ";
	displayInfos(list[2]) ;
	std::cout << " wrapped inside a ";
	displayInfos(list[1]);
	std::cout << " !!" << std::endl;
}

int	main(int ac, char **av)
{
	std::string	filename;
	std::ifstream	f;
	std::string	line;
	std::string	content;
	std::vector<std::string>	list;

	for (int i = 1; i < ac; i++) {
		f.open(av[i]);
		if (!f.good()) {
			std::cerr << "Santa: The gift tagged " << av[i] <<
				" is too damaged or nonexistent" << std::endl;
			return (84);
		} else {
			content = "";
			while (!f.eof()) {
				getline(f, line);
				content += line;
			}
			f.close();
			list = getPresentList(content);
			if (!checkList(list)) {
				std::cerr << "Santa: I cannot identify the "
					  << "gift tagged "
					  << av[i] << std::endl;
				return (84);
			} else {
				std::cout << "Santa: I am opening the present "
					  << av[i] << " now." << std::endl;
				openPresent(list);
			}
		}
	}
	if (ac == 1)
		std::cout << "./santa file1.xml [...]" << std::endl;
	std::cout << std::endl;
	return (0);
}
