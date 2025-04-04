/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:31:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 12:57:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie will survive for the whole ~~world~~ program.
// You are in your citadel, you peek out of the window 
// and you see a Zombie. He spots you back, turns to you and tries to walk to you.
// Afraid, you break the line of sight BUT the Zombie tries to get to you by any mean.
// I guess you have to kill it. Or delete it.
Zombie* newZombie( std::string name )
{
	Zombie *newZombie;

	newZombie = new Zombie(name);
	return (newZombie);
}
