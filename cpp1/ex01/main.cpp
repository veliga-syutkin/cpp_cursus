/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:26:25 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/09 12:26:09 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

void	instantZombie()
{
	Zombie zombieInstant("Instant");
	zombieInstant.announce();
}

void	announceHorde(Zombie *horde, int N)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << i << " ";
		horde[i].announce();
	}
}

// void	hordeNot(Zombie *horde, int N)
// {
// 	for (uint i = N; i >= 0; i--)
// 	{
// 		std::cout << i << " ";
// 		horde[i].~Zombie();
// 	}
// }

int main(void)
{
	std::srand(std::time(0));
	try
	{
		Zombie *zombieVillager = NULL;
		Zombie *horde_of_zombies = NULL;
		int	ZOMBIE_HORDE_SIZE = std::rand()%100 + 1; //returns a random number between 1 and 100
		try
		{
			zombieVillager = newZombie("Pillager");
			std::cout << "Here's dynamically allocated Zombie: " << &zombieVillager << std::endl;
			std::cout << "He's acessible from anywhere by the pointer." << std::endl;
			instantZombie();
			std::cout << "Oh... That zombie got splashed real hard. He's not more than a pool of meat now." << std::endl;
			std::cout << "But the dynamically allocated Zombie is still alive." << std::endl;
			std::cout << "Let's make him announce himself." << std::endl;
			zombieVillager->announce();
			std::cout << "Hey, look! He's eating someone!" << std::endl;
			randomChump("Random");
			std::cout << "Look at the other side of the window, there are a lot of Zombies!" << std::endl;
			std::cout << "OH NO! That's a horrible horde of Zombies!" << std::endl;
			horde_of_zombies = zombieHorde(ZOMBIE_HORDE_SIZE, "Zomby in Horde");
		}
		catch (...)
		{
			delete zombieVillager;
			delete[] horde_of_zombies;
			std::cerr << "Memory allocation failed" << std::endl;
			throw;
		}

		std::cout << "*ZOMBIE HORDE*:" << std::endl;
		announceHorde(horde_of_zombies, ZOMBIE_HORDE_SIZE);

		std::cout << "BEWARE! THERE IS A TRUCK COMING ON THE HORDE!" << std::endl;
		delete[] horde_of_zombies;

		std::cout << "Welp, the horde is no more." << std::endl;
		std::cout << "Let's just kill that dynamically allocated Zombie..." << std::endl;
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
