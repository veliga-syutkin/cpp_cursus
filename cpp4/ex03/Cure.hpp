/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 08:07:43 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "../terminal_colors.hpp"
# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		Cure();                                	// Default constructor
		Cure(const Cure &other);         	// Copy constructor
		Cure &operator=(const Cure &other); // Assignment operator
		~Cure();                                	// Destructor

		AMateria *clone() const;		// override;
		void use(ICharacter &target);	// override;
};

#endif // CURE_HPP
