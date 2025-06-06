/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 07:52:54 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "../terminal_colors.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{
	private:										// Private members
		AMateria	*_inventory[4];					// Array of pointers to AMateria
		short		_inventoryIndex;
		std::string	_name;
		int			_whereFreeSlot();
	protected:										// Protected members for inheritance

	public:
		Character();                                	// Default constructor
		Character(const Character &other);         	// Copy constructor
		Character &operator=(const Character &other); // Assignment operator
		~Character();                                	// Destructor

		Character(std::string const &name);         	// Constructor with name
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		AMateria*	getMateriaPtr(int idx) const;
};

#endif // CHARACTER_HPP
