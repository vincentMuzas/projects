/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#ifndef _BOX_HPP_
# define _BOX_HPP_

#include "Wrap.hpp"

class	Box : public Wrap {
public:
        Box(const std::string &title = "BasicBox");
        ~Box();

        bool	wrapMeThat(Object *);
};

#endif
