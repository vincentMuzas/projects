/*
** EPITECH PROJECT, 2018
** Santa Claus
** File description:
**
*/

#include <fstream>
#include "../includes/GiftDatas.hpp"

GiftDatas::GiftDatas(GiftPaper *pack)
{
	this->p_count = 0;
        this->p_giftpaper = pack;
        this->p_box = nullptr;
        this->p_present = nullptr;
        if (pack != nullptr) {
                this->p_box = static_cast<Box *>(this->p_giftpaper->getObj());
                if (this->p_box != nullptr) {
                        this->p_present = static_cast<Toy *>(
                        		this->p_box->getObj());
                }
        }
        if (this->p_present != nullptr)
                this->p_title = this->p_present->getTitle();
}

GiftDatas::~GiftDatas()
{  
}

void	GiftDatas::load(GiftPaper *pack)
{
        this->p_giftpaper = pack;
        this->p_box = nullptr;
        this->p_present = nullptr;
        if (pack != nullptr) {
                this->p_box = static_cast<Box *>(this->p_giftpaper->getObj());
                if (this->p_box != nullptr) {
                        this->p_present = static_cast<Toy *>(
                        		this->p_box->getObj());
                }
        }
        if (this->p_present != nullptr)
                this->p_title = this->p_present->getTitle();
}

void	GiftDatas::writeContent(std::ofstream &giftfile)
{
        giftfile << "<Gift MagicNumber=\"0xDEADBEEF\">" << std::endl;
        giftfile << "\t<Wrap Type=\""
        	<< this->p_giftpaper->getTypeName() << "\" Title=\""
		<< this->p_giftpaper->getTitle() << "\">" << std::endl;
        giftfile << "\t\t<Wrap Type=\"" << this->p_box->getTypeName()
        	<< "\" Title=\""  << this->p_box->getTitle() << "\">"
		<< std::endl;
        giftfile << "\t\t\t<Toy Type=\""
        	<< this->p_present->getTypeName() << "\" Title=\""
		<< this->p_present->getTitle()<< "\"/>" << std::endl;
        giftfile << "\t\t</Wrap>" << std::endl;
        giftfile << "\t</Wrap>" << std::endl;
        giftfile << "</Gift>";
}

void GiftDatas::generateXMLFile()
{
        std::ofstream giftfile (this->p_title + '_' +
        		std::to_string(this->p_count) + ".xml");
        if (this->p_present != nullptr && this->p_giftpaper != nullptr
        		&& this->p_box != nullptr) {
        	this->writeContent(giftfile);
        	this->p_count += 1;
        }
        else
                std::cerr << "Error generating file";
        giftfile.close();
}
