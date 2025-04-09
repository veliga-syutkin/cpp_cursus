/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 04:54:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/09 12:26:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define zombieSay "BraiiiiiiinnnzzzZ..."
// # define ZOMBIE_HORDE_SIZE 10
// # define uint unsigned int

class Zombie
{
	private:
	std::string _name;
	
	public:
	void setName(std::string name);
	// void getName(std::string name);
	void	announce(void);
	Zombie();
	Zombie(std::string name);
	~Zombie();
};

/* ************************************************************************** */
// Global functions

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif