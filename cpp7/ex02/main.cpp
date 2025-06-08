/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:20:56 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/08 14:46:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

int main()
{
	{
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = i * 10;
		}

		std::cout << "Contents of intArray:" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}

		Array<int> copyArray(intArray);
		std::cout << "Contents of copyArray after copy constructor:" << std::endl;
		for (unsigned int i = 0; i < copyArray.size(); ++i)
		{
			std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
		}
	}
	std::cout << TERMINAL_BG_RED << TERMINAL_WHITE << "EXCEPTIONS TESTS" << TERMINAL_RESET << std::endl;
	{
		try
		{
			Array<int> intArray(5);
			std::cout << "Contents of intArray before accessing out of bounds:" << std::endl;
			for (unsigned int i = 0; i < intArray.size(); ++i)
			{
				std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
			}
			std::cout << "Accessing out of bounds index:" << std::endl;
			std::cout << intArray[10] << std::endl; // This should throw an exception
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}
	std::cout << TERMINAL_CYAN << "\nmain.cpp from project page" << TERMINAL_RESET << std::endl;
	{
		# define MAX_VAL 750
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		return 0;
	}

	return 0;
}