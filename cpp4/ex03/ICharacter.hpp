/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:20:10 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/28 13:41:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include "../terminal_colors.hpp"
# include "AMateria.hpp"
# include <iostream>

class AMateria; // Forward declaration to avoid circular dependency

class ICharacter
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		/* Class Interface - thus C.O.F. doesn't apply: 
		ICharacter();                                	// Default constructor
		ICharacter(const ICharacter &other);         	// Copy constructor
		ICharacter &operator=(const ICharacter &other); // Assignment operator
		*/
	// Virtual deconstructor, void-defined in .hpp is tolerated to avoid create almost empty .cpp file
		virtual ~ICharacter() { };                                	// Destructor

		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;

		virtual AMateria *getMateriaPtr(int idx) const = 0; // Returns a pointer to the materia at index idx
};

#endif // ICHARACTER_HPP
