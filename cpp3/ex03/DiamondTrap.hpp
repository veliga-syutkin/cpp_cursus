/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:08:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 18:07:03 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:										// Private members
		std::string	_name;                         // DiamondTrap's name, separate from ClapTrap's name

	protected:										// Protected members for inheritance

	public:
		DiamondTrap();                                	// Default constructor
		DiamondTrap(const DiamondTrap &other);         	// Copy constructor
		DiamondTrap &operator=(const DiamondTrap &other); // Assignment operator
		~DiamondTrap();  								// Destructor

		DiamondTrap(std::string name);
		void whoAmI();                                 // Method to print the DiamondTrap's name
};

#endif // DiamondTrap_HPP
