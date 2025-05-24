/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:28:03 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 15:13:17 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		ScavTrap();                                	// Default constructor
		ScavTrap(const ScavTrap &other);            	// Copy constructor
		ScavTrap &operator=(const ScavTrap &other); 	// Assignment operator
		~ScavTrap();                               	// Destructor

		ScavTrap(const std::string &name);           // Constructor with name parameter
		void	attack(const std::string &target); // override; // `override` to indicate that this method is willingly remplacing method from the base class (good practice)
		void	guardGate();                        // New method specific to ScavTrap
};

#endif // SCAVTRAP_HPP
