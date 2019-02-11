/*
** EPITECH PROJECT, 2019
** cpp_d07a_2018
** File description:
** Skat
*/

#ifndef SKAT_HPP_
	#define SKAT_HPP_

#include <string>
#include <iostream>

class  Skat
{
	public:
		Skat(const  std::string &name, int  stimPaks = 15);
		Skat();
		~Skat();
		int stimPaks ();
		int stimPaks(int val);
		const  std:: string &name();
		void  shareStimPaks(int  number , Skat &stock);
		void  addStimPaks(unsigned  int  number);
		void  useStimPaks ();
		void  status ();
	public:
		const std::string &_name;
		int _stimPaks;
//	[...]
};

#endif /* !SKAT_HPP_ */
