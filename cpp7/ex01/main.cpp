/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 20:33:26 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename type_element>
void show_element(type_element element)
{
	std::cout << element;
}

int	main(void)
{
	std::cout << "Tests 1 :" << std::endl;
	{
		char buffer1[10] = "abcdefijk";
		int buffer2[10] = {1,2,3,4,5,6,7,8,9,10};

		iter(buffer1, 9, show_element);
		std::cout << std::endl;

		iter(buffer2, 10, show_element);
		std::cout << std::endl;
	}
	std::cout << "Tests 2 :" << std::endl;
	{
		const char buffer1[10] = "abcdefijk";
		const int buffer2[10] = {1,2,3,4,5,6,7,8,9,10};

		iter(buffer1, 9, show_element);
		std::cout << std::endl;

		iter(buffer2, 10, show_element);
		std::cout << std::endl;
	}
}