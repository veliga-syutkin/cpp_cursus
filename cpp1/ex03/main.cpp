/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:13:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/08 06:44:58 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		// std::cout << "[DEBUG] weapon type: " << club.getType() << std::endl;
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		// std::cout << "[DEBUG] weapon type: " << club.getType() << std::endl;
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		// std::cout << "[DEBUG] weapon type: " << club.getType() << std::endl;
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		// std::cout << "[DEBUG] weapon type: " << club.getType() << std::endl;
		jim.attack();
	}
	{
		Weapon fists = Weapon("fists");
		HumanB raven("Raven");
		raven.attack();
		// raven.setWeapon(NULL); // OUT OF SCOPE OF THE PROJECT
		raven.setWeapon(fists);
		raven.attack();
		fists.setType("kicking shoes");
		raven.attack();
	}
	{
		// HumanA bob("Bob", NULL); // OUT OF SCOPE OF THE PROJECT		
		// HumanA bob("Bob"; NULL);
	}
	return 0;
}