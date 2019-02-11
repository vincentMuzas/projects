/*
** EPITECH PROJECT, 2019
** cpp_d17_2018
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
	#define ENCRYPTION_HPP_

#include "IEncryptionMethod.hpp"

class Encryption {
	public:
		Encryption(IEncryptionMethod &method, void (ptr)(int));
		~Encryption();
	protected:
	private:
		void (fnptr)(int);
};

#endif /* !ENCRYPTION_HPP_ */
