/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 04:54:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 13:37:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define zombieSay "BraiiiiiiinnnzzzZ..."

class Zombie
{
	private:
	std::string _name;
	
	public:
	void	announce(void);
	Zombie(std::string name);
	~Zombie();
};

/* ************************************************************************** */
// Global functions

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif