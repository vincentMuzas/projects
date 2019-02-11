/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true)
{
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *QuantumReactor)
: _coreReactor(QuantumReactor)
{

}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
	return (this->_coreReactor);
}

void WarpSystem::QuantumReactor::setStability(bool val)
{
	this->_stability = val;
}