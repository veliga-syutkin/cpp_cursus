/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/10 11:16:18 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void toUpper(char& element)
{

		if (element >= 'a' && element <= 'z')
			element -= 32;
}

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
		Teste() : _n(42) { return;}
		int get() const { return this->_n; }
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
	std::cout << TERMINAL_GREEN << "Tests 1 :" << std::endl;
	{
		char subtest_1a[] = "abcdefijk";
		int subtest_1b[] = {1,2,3,4,5,6,7,8,9,10};

		iter(subtest_1a, 9, show_element);
		std::cout << std::endl;

		iter(subtest_1b, 10, show_element);
		std::cout << TERMINAL_RESET << std::endl;
	}
	std::cout << TERMINAL_CYAN << "Tests 2 :" << std::endl;
	{
		const char subtest_2a[] = "abcdefijk";
		const int subtest_2b[] = {1,2,3,4,5,6,7,8,9,10};

		iter(subtest_2a, 9, show_element);
		std::cout << std::endl;

		iter(subtest_2b, 10, show_element);
		std::cout << TERMINAL_RESET << std::endl;
	}
	std::cout << "Tests 3 :" << std::endl;
	{
		int tab[] = {0, 1, 2, 3, 4};
		Teste tab2[5];

		iter(tab, 5, print);
		iter(tab2, 5, print);
		std::cout << std::endl;
	}
	std::cout << "Tests 4 :" << std::endl;
	{
		char subtest_1a[] = "abcdefijk";

		iter(subtest_1a, 9, toUpper);
		std::cout << subtest_1a << std::endl;
	}
	std::cout << TERMINAL_BG_RED << "There is NO WAY for `iter` function to check\n\
	by itself if the memory is beholding to main program or not."<< TERMINAL_RESET << std::endl;
	// Uncomment the following to check that: 
	// {
	// 	int tab[] = {0, 1, 2, 3, 4};
	// 	const int tab2[] = {5, 6, 7, 8, 9};

	// 	iter(tab, 6, print);
	// 	iter(tab2, 100, print);
	// 	std::cout << TERMINAL_RESET << std::endl;
	// }
	return (0);
}
