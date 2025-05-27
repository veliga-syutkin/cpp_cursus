/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 07:52:54 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

# include "../terminal_colors.hpp"
# include "AMateria.hpp"
# include <iostream>

class IMateriaSource
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		/* Class Interface - thus C.O.F. doesn't apply:
		IMateriaSource();                                	// Default constructor
		IMateriaSource(const IMateriaSource &other);         	// Copy constructor
		IMateriaSource &operator=(const IMateriaSource &other); // Assignment operator
		*/
	// Virtual deconstructor, void-defined in .hpp is tolerated to avoid create almost empty .cpp file
		virtual ~IMateriaSource() { };                                	// Destructor

		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // IMATERIASOURCE_HPP
