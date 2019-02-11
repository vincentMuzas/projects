/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#include "../includes/Box.hpp"
#include "../includes/Object.hpp"

Box::Box(const std::string & title): Wrap(title)
{
        this->c_objIn = nullptr;
        this->c_type = Object::ObjectType::Box;
}

Box::~Box()
{
}

bool Box::wrapMeThat(Object *barePresent)
{
        if (this->c_objIn != nullptr) {
                std::cerr << CANT_WRAP_MORE_BOX << std::endl;
                return (false);
        }
        if (barePresent == nullptr) {
                std::cerr << CANT_WRAP_INEXISTANT_BOX << std::endl;
                return (false);
        }
        if (barePresent->isWrapped()) {
                std::cerr << CANT_WRAPED_ALREADY_BOX << std::endl;
                return (false);
        }
        if (!this->isOpen()) {
                std::cerr << CANT_WRAP_BOX_CLOSED_BOX << std::endl;
                return (false);
        }
        if (!(barePresent->is(ObjectType::Toy))) {
                std::cerr << BOX_ONLY_TOY << std::endl;
                return (false);
        }
        this->placeObj(barePresent);
        this->c_objIn->setWrapped(true);
        return (true);
}
