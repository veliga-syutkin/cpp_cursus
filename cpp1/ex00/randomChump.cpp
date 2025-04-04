/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:30:56 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 12:54:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// You are in your citadel, you peek out of the window 
// and you see a Zombie. He spots you back, turns to you and tries to walk to you.
// Afraid, you break the line of sight and the Zombie forgets you and returns to do Zombie stuff.
void randomChump( std::string name )
{
	Zombie pillager(name);
	pillager.announce();
}
