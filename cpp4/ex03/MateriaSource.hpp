/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 07:52:54 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "../terminal_colors.hpp"
# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
	private:										// Private members
		AMateria	*_materia[4];
		int			_indexMateria;
	protected:										// Protected members for inheritance

	public:
		MateriaSource();                                	// Default constructor
		MateriaSource(const MateriaSource &other);         	// Copy constructor
		MateriaSource &operator=(const MateriaSource &other); // Assignment operator
		~MateriaSource();                                	// Destructor

		void learnMateria(AMateria *m); // override;          // Learn a new materia
		AMateria *createMateria(std::string const &type); // override; // Create a materia
};

#endif // MATERIASOURCE_HPP
