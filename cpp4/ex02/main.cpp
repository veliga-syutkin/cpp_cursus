/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:42:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 21:17:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <ctime>

# define SEPERATOR "----------------------------------------"

int main()
{
	std::srand(std::time(0));
	int ANIMAL_COUNT = (std::rand() % 5 + 1); // returns a random number between 1 and 5
	Cat *cats = new Cat[ANIMAL_COUNT];
	Dog *dogs = new Dog[ANIMAL_COUNT];

	std::cout << SEPERATOR << std::endl;
	std::cout << "CATS:" << std::endl;
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << SEPERATOR << std::endl;
		cats[i].makeSound();
		std::cout << "Cat " << i + 1 << " ideas: " << std::endl;
		for (int j = 0; j < 100; j++)
		{
			std::cout << cats[i].getIdea(j) << ", ";
		}
	}
	std::cout << std::endl << SEPERATOR << std::endl;
	std::cout << "DOGS:" << std::endl;
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << SEPERATOR << std::endl;
		dogs[i].makeSound();
		std::cout << "Dog " << i + 1 << " ideas: " << std::endl;
		for (int j = 0; j < 100; j++)
		{
			std::cout << dogs[i].getIdea(j) << ", ";
		}
	}
	std::cout << std::endl << SEPERATOR << std::endl;

	delete[] cats;
	delete[] dogs;
	std::cout << std::endl << SEPERATOR << std::endl;
	std::cout << std::endl << SEPERATOR << std::endl;
	{
		Dog basic;
		{
			Dog tmp = basic; // Copy constructor
			tmp.makeSound();
			tmp.getIdea(0);
		} // Destructor called for tmp
		basic.makeSound();
		basic.getIdea(0);
	}
/* Uncomment following to test uncompilability of abstract class Animal.*/
	// {
	// 	Animal test; 
	// }
	return 0;
}