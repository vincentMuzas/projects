/*
** EPITECH PROJECT, 2020
** CPP_abstractvm_2019
** File description:
** CPU
*/

#pragma once

#include "IComponents.hpp"
#include "Memory.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"
#include <map>
#include <vector>
#include <sstream>

#define UNUSED(expr) do { (void)(expr); } while (0)

#define MAX_TYPE(op1, op2) (op1.getType() >= op2.getType() ? op1 : op2)
#define MIN_TYPE(op1, op2) (op1.getType() < op2.getType() ? op2 : op1)

class CPU : IComponents {
	public:
		CPU();
		~CPU();

        enum fnts {
            push, pop, clear,
            dup, swap, dump,
            assert, add, sub,
            mul, div, mod,
            load, store, print,
            exit
        };

        enum op_type {
            e_int8, e_int16,
            e_int32, e_float,
            e_double, e_bigdecimal
        };

        std::string call(fnts, std::string &cmd);

	private:
        std::string f_push(std::string &cmd);
        std::string f_pop(std::string &cmd);
        std::string f_clear(std::string &cmd);
        std::string f_dup(std::string &cmd);
        std::string f_swap(std::string &cmd);
        std::string f_dump(std::string &cmd);
        std::string f_assert(std::string &cmd);
        std::string f_add(std::string &cmd);
        std::string f_sub(std::string &cmd);
        std::string f_mul(std::string &cmd);
        std::string f_div(std::string &cmd);
        std::string f_mod(std::string &cmd);
        std::string f_load(std::string &cmd);
        std::string f_store(std::string &cmd);
        std::string f_print(std::string &cmd);
        std::string f_exit(std::string &cmd);

        std::string get_arg(std::string &cmd);
        bool is_float_convertible(std::string &cmd);
  
        std::map<fnts, std::string (CPU::*)(std::string &)> m_fnts;
        std::map<eOperandType, std::string> m_op_type;
        std::vector<const IOperand *> registers;
        Memory ram;
};