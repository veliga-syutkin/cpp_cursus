/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/08 14:47:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename type_element>
void show_element(type_element element)
{
	std::cout << element;
}

class Teste
{
	private: 
		int _n;
	public:
		Teste(void) : _n(42) { return;}
		int get(void) const { return this->_n; }
};

std::ostream & operator<<(std::ostream & o, Teste const & rhs)
{
	o << rhs.get();
	return o;
}

template<typename T>
void print(T const & x)
{
	std::cout << x << std::endl;
	return;
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
	std::cout << "Tests 3 :" << std::endl;
	{
		int tab[] = {0, 1, 2, 3, 4}; // is that legal?
		Teste tab2[5];

		iter(tab, 5, print);
		iter(tab2, 5, print);
		std::cout << std::endl;
	}
	return (0);
}
