/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#ifndef _WRAP_HPP_
# define _WRAP_HPP_

#include "Object.hpp"

class	Wrap : public Object {
public:
        Wrap(const std::string &);
        virtual	~Wrap();

        bool	isOpen();
        void	setIsOpen(bool);
        bool virtual	wrapMeThat(Object *) = 0;
        void	openMe() { this->c_open = true; };
        void	closeMe() { this->c_open = false; };
        void	placeObj(Object *);
        Object	*extractObj();
        Object	*getObj();
        bool	isEmpty();

protected:
        bool	c_open;
        Object	*c_objIn;
        Wrap();
};

#endif
