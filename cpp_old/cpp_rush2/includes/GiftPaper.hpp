/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#ifndef _GIFTPAPER_HPP_
# define _GIFTPAPER_HPP_

#include "Wrap.hpp"

class	GiftPaper : public Wrap {
public:
        GiftPaper(const std::string &t = "GiftPaper");
        ~GiftPaper();

        bool	wrapMeThat(Object *) override;
};

#endif
