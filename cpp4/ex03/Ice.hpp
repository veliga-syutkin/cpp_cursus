/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 08:07:43 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "../terminal_colors.hpp"
# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		Ice();                                	// Default constructor
		Ice(const Ice &other);         	// Copy constructor
		Ice &operator=(const Ice &other); // Assignment operator
		~Ice();                                	// Destructor

		AMateria *clone() const;		// override;
		void use(ICharacter &target);	// override;
};

#endif // ICE_HPP
