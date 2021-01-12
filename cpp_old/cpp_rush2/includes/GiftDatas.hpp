/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#ifndef _GIFT_HPP_
# define _GIFT_HPP_

#include "Object.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "Toy.hpp"

class	GiftDatas {
public:
        GiftDatas(GiftPaper *content = nullptr);
        ~GiftDatas();

        void	load(GiftPaper *content);
        void	generateXMLFile();
        void	writeContent(std::ofstream &);

private:
        GiftPaper	*p_giftpaper;
        Box		*p_box;
        Toy		*p_present;
        std::string	p_title;
        unsigned int	p_count;
};

#endif
