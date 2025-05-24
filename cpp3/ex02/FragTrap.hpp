/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:55:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 16:57:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		FragTrap();                                	// Default constructor
		FragTrap(const FragTrap &other);         	// Copy constructor
		FragTrap &operator=(const FragTrap &other); // Assignment operator
		~FragTrap();                                	// Destructor
		FragTrap(const std::string &name);          // Constructor with name parameter
		void	highFivesGuys();                // Method to request high fives
};

#endif // FRAGTRAP_HPP
