/*
** EPITECH PROJECT, 2018
** object.hpp
** File description:
**
*/

#ifndef OBJECT_HPP_
# define OBJECT_HPP_

# include <string>
# include <iostream>

const std::string	ERROR_NOT_EMPTY = "The ConveyorBelt slot is not empty";
const std::string	ERROR_IS_EMPTY = "The ConveyorBelt slot is empty";
const std::string	ERROR_USABLE = "The ConveyorBelt is not usable";

const std::string	CANT_WRAP_MORE_GP =
	"Error: Unable to wrap more than one Box with the Giftpaper";
const std::string	CANT_WRAP_INEXISTANT_GP =
	"Error: Unable to wrap a nonexistent Box with the Giftpaper";
const std::string	CANT_WRAPED_ALREADY_GP =
	"Error: Unable to wrap an already warped Box with the Giftpaper";
const std::string	CANT_WRAP_MORE_BOX =
	"Error: Unable to wrap more than one Toy with the Box";
const std::string	CANT_WRAP_INEXISTANT_BOX =
	"Error: Unable to wrap a nonexistent Toy with the Box";
const std::string	CANT_WRAPED_ALREADY_BOX =
	"Error: Unable to wrap an already warped Toy with the Box";
const std::string	CANT_WRAP_BOX_CLOSED_BOX =
	"Error, cannot warp if the box is closed";
const std::string	BOX_ONLY_TOY =
	"Error, the Box can only contain a Toy (Pony or Teddy)";
const std::string	GP_ONLY_BOX =
	"Error: A GiftPaper can only wrap a Box";

const std::string	NO_TABLE_CONVOYER = "Table or Conveyer Belt missing";

const std::string	CANT_CREATE_GIFT =
	"o'pa ere's somin' wron' in da box!";
const std::string	WIERD_TEDDY_SCREAMING_LOUDLY = "gra hu";
const std::string	LITTLE_PONY_S_FRIENDLY_SCREAM = "yo man";

const std::string	ELVES_TAKE_WRAP = "whistles while working";
const std::string	ELVES_WRAP_OBJ = "tuuuut tuuut tuut";


///
/// @brief An object used to create gifts.
///
/// Represent any part of a gift like a toy or a box.
///
class Object {
public:
	///
	/// @brief The object type
	///
	enum	ObjectType {
		None = 0,            //!< None
		Toy = 1,             //!< Toy
		Wrap = 2,            //!< Wrap
		Teddy = 4 | Toy,     //!< Teddy
		LittlePony = 8 | Toy,//!< LittlePony
		Box = 16 | Wrap,     //!< Box
		GiftPaper = 32 | Wrap//!< GiftPaper
	};

public:
	Object(const std::string &title);
	virtual ~Object();

	bool	operator==(ObjectType type) const;
	bool	operator!=(ObjectType type) const;

	bool	is(const ObjectType type) const;

	virtual bool	isTaken() const;

	///
	/// @brief Gets the object's wrap state.
	///
	/// Gets whenever this object is wrapped into another or not.
	///
	/// @return Returns `true` if this object is wrapped into another,
	/// 	`false` otherwise.
	///
	bool		isWrapped() const { return (p_wrapped); };

	///
	/// @brief Gets this object's type.
	///
	/// @return Returns this object {@link ObjectType type}.
	///
	ObjectType	getType() const { return (c_type); };

	///
	/// @brief Gets this object's type name.
	///
	/// @return Returns this object {@link ObjectType type} name.
	///
	std::string	getTypeName() const;

	///
	/// @brief Sets this object's wrap state.
	///
	/// Define whenever this object is wrapped into another or not.
	///
	/// @param status The new wrap state.
	///
	void		setWrapped(bool status);

	///
	/// @brief The object's name / title.
	///
	/// Gets this object's title.
	///
	/// @return Returns this object's title.
	///
	std::string	getTitle() const { return (p_title); };

	///
	/// @brief Sets the object's name / title.
	///
	/// Change the title associated with this object.
	///
	/// @param name The new title for this object.
	///
	void		setTitle(const std::string &name);

protected:
	ObjectType	c_type;

private:
	std::string	p_title;
	bool		p_taken;
	bool		p_wrapped;
};

#endif /* !OBJECT_HPP_ */
