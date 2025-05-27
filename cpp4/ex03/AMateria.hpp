/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:41:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/27 08:41:59 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include "../terminal_colors.hpp"
# include "ICharacter.hpp"
# include <iostream>

class AMateria
{
	private:										// Private members

	protected:										// Protected members for inheritance
		std::string _type;							// Materia type

	public:
		AMateria();                                	// Default constructor
		AMateria(const AMateria &other);         	// Copy constructor
		AMateria &operator=(const AMateria &other); // Assignment operator
		~AMateria();                                	// Destructor

		AMateria(std::string const &type);
		std::string const &getType() const;			// Returns the materia type;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;
};

#endif // AMATERIA_HPP
