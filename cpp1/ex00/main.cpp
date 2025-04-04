/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:26:25 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 13:38:05 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	instantZombie()
{
	Zombie zombieInstant("Instant");
	zombieInstant.announce();
}

int main(void)
{
	try
	{
		Zombie *zombieVillager = newZombie("Pillager");
		std::cout << "Here's dynamically allocated Zombie: " << &zombieVillager << std::endl;
		std::cout << "He's acessible from anywhere by the pointer." << std::endl;
		instantZombie();
		std::cout << "Oh... That zombie got splashed real hard. He's not more than a pool of meat now." << std::endl;
		std::cout << "But the dynamically allocated Zombie is still alive." << std::endl;
		std::cout << "Let's make him announce himself." << std::endl;
		zombieVillager->announce();
		std::cout << "Hey, look! He's eating someone!" << std::endl;
		randomChump("Random");
		std::cout << "It's time to kill that dynamically allocated Zombie, don't you think so?" << std::endl;
		delete zombieVillager;
		std::cout << "Here we go, no more Zombies on the horizon!" << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (1);
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred." << std::endl;
		return (1);
	}
}
