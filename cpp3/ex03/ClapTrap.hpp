/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:32:32 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 20:37:25 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "../terminal_colors.hpp"
#include <iostream>
#include <climits>

class ClapTrap
{
	private:										// Private members
		
	protected:										// Protected members for inheritance
		std::string		_name;
		unsigned int	_hp;
		int				_energy;
		int				_attack_damage;

		bool			isAble();
	
	public:
		ClapTrap();                                	// Default constructor
		ClapTrap(const ClapTrap &other);            	// Copy constructor
		ClapTrap &operator=(const ClapTrap &other); 	// Assignment operator
		~ClapTrap();                               	// Destructor

		ClapTrap(const std::string &name);           // Constructor with name parameter
		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amoutn);
};

#endif // CLAPTRAP_HPP
