/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:12:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 21:06:08 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Based.hpp"
#include "../terminal_colors.hpp"

#define NUM_TESTS 3

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator

	std::cout << TERMINAL_BG_YELLOW << "\n\n\tIdentifying through references: " << TERMINAL_RESET << std::endl;
	for (int i = 0; i < NUM_TESTS; ++i) // Generate 10 random objects
	{
		std::cout << "\n"; 
		Based *obj = generate();
		identify(obj);
		delete obj; // Clean up the dynamically allocated memory
	}
	std::cout << TERMINAL_BG_YELLOW << "\n\n\tIdentifying through pointers: " << TERMINAL_RESET << std::endl;
	for (int i = 0; i < NUM_TESTS; ++i) // Generate 10 random objects
	{
		std::cout << "\n"; 
		Based *obj = generate();
		identify(*obj);
		delete obj; // Clean up the dynamically allocated memory
	}

};
