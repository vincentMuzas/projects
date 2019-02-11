/*
** EPITECH PROJECT, 2019
** cpp_d08_2018
** File description:
** Droid
*/

#ifndef DROID_HPP_
	#define DROID_HPP_

#include <string>
#include <iostream>

class Droid {
	public:
		Droid(std::string serial);
		Droid(Droid &old);
		~Droid();
		std::string getId() const {return (Id);};
		size_t getEnergy() const {return (Energy);};
		size_t getAttack() const {return (Attack);};
		size_t getToughness() const {return (Toughness);};
		std::string *getStatus() const {return (Status);};
		size_t getFingerPrint() const {return (FingerPrint);};
		size_t getExp() const {return (Exp);};
		void setId(std::string val) {this->Id = val;};
		void setEnergy(size_t val) {this->Energy = val;};
		void setStatus(std::string *val) {this->Status = val;};
		void setFingerPrint(size_t val) {this->FingerPrint = val;};
		void setExp(size_t val) {this->Exp = val;};
		bool operator==(const Droid &rop);
		bool operator!=(const Droid &rop);
		Droid &operator=(const Droid &rop);
	protected:
	private:
		std::string Id;
		size_t Energy;
		const size_t Attack;
		const size_t Toughness;
		std::string *Status;
		size_t FingerPrint;
		size_t Exp;
};

std::ostream &operator<<(std::ostream &s, const Droid &src);
Droid &operator<<(Droid &lop, size_t &rop);

#endif /* !DROID_HPP_ */
