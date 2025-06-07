/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:20:56 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 21:21:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
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

	return 0;
}