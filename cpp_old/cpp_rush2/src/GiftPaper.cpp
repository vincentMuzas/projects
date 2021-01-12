/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#include "../includes/GiftPaper.hpp"

GiftPaper::GiftPaper(const std::string & title): Wrap(title)
{
        this->c_type = Object::ObjectType::GiftPaper;
        this->c_objIn = nullptr;
}

GiftPaper::~GiftPaper()
{
}

bool GiftPaper::wrapMeThat(Object *bareBox)
{
        if (this->c_objIn != nullptr) {
                std::cerr << CANT_WRAP_MORE_GP << std::endl;
                return (false);
        }
        if (bareBox == nullptr) {
                std::cerr << CANT_WRAP_INEXISTANT_GP << std::endl;
                return (false);
        }
        if (bareBox->isWrapped()) {
                std::cerr << CANT_WRAPED_ALREADY_GP << std::endl;
                return (false);
        }
        if (!(bareBox->is(ObjectType::Box))) {
                std::cerr << GP_ONLY_BOX << std::endl;
        }
        this->placeObj(bareBox);
        this->c_objIn->setWrapped(true);
        return (true);
}
