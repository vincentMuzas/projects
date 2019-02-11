/*
** EPITECH PROJECT, 2018
** toy.hpp
** File description:
** 
*/

#ifndef TOY_HPP_
# define TOY_HPP_

# include "Picture.hpp"
#include <memory>

class Toy {
public:
	class Error {
	public:
		Error();
		~Error() {};
		enum ErrorType {
			UNKNOWN,
			PICTURE,
			SPEAK
		};
		std::string what();
		std::string where();
		int type;
	};
	enum type_e {
		BASIC_TOY,
		ALIEN,
		BUZZ,
		WOODY
	};
	Toy();
	Toy(int type, std::string Name, std::string FileName);
	~Toy() {};
	int getType() const;
	std::string getName() const;
	bool setName(std::string Name);
	bool setAscii(std::string fileName);
	std::string getAscii() const;
	virtual bool speak(std::string say);
	virtual bool speak_es(std::string say);
	Toy operator<<(std::string rop);
	Error getLastError();
protected:
	const int _type;
	std::string _Name;
	std::string _ascii;
	Toy::Error lastErr;
};

std::ostream &operator<<(std::ostream &lop, Toy &rop);

#endif
