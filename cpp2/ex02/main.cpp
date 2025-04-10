/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:36:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/11 00:47:45 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <climits>

int main( void )
{
	// {
	// 	Fixed a;
	// 	// a.setStr("This is A object.");

	// 	Fixed b( a );
	// 	Fixed c;

	// 	// c.setStr("This is C object.");

	// 	// a.print();
	// 	// b.print();
	// 	// c.print();

	// 	c = b;
	// 	std::cout << a.getRawBits() << std::endl;
	// 	std::cout << b.getRawBits() << std::endl;
	// 	std::cout << c.getRawBits() << std::endl;
	// }
	// {
	// 	std::cout << "\n" << std::endl;
	// 	Fixed a;
	// 	Fixed const b( 10 );
	// 	Fixed const c( 42.42f );
	// 	Fixed const d( b );
	// 	a = Fixed( 1234.4321f );
	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;
	// 	std::cout << "c is " << c << std::endl;
	// 	std::cout << "d is " << d << std::endl;
	// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// }
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // multiplication
		std::cout << b << std::endl;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		// Addition
		std::cout << "\n" << std::endl;
		Fixed c = a + b;
		std::cout << "C: " << c << std::endl;

		// Division
		Fixed d ( Fixed( 0.5f ) / Fixed( 2 ) );
		std::cout << "D: " << d << std::endl;

		// Subtraction
		Fixed e = a - b;
		std::cout << "E: " << e << std::endl;
	}
	// {
	// 	Fixed a( 5.05f );
	// 	Fixed b( 2 );
	// 	std::cout << "A: " << a << std::endl;
	// 	std::cout << "B: " << b << std::endl;
	// 	std::cout << Fixed::min( a, b ) << std::endl;
	// 	std::cout << Fixed::max( a, b ) << std::endl;
	// 	std::cout << Fixed::min( a, b ) << std::endl;
	// 	std::cout << Fixed::max( a, b ) << std::endl;
	// }
	// {
	// 	Fixed a( 5.05f );
	// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // multiplication
	// 	std::cout << b << std::endl;
	// 	std::cout << a << std::endl;
	// 	std::cout << ++a << std::endl;
	// 	std::cout << a << std::endl;
	// 	std::cout << a++ << std::endl;
	// 	std::cout << "A: " << a << std::endl;
	// 	std::cout << "B: " << b << std::endl;
	// 	std::cout << Fixed::max( a, b ) << std::endl;

	// 	// Addition
	// 	std::cout << "\n" << std::endl;
	// 	Fixed c = a + b;
	// 	std::cout << "C: " << c << std::endl;

	// 	// Division
	// 	Fixed d ( Fixed( 0.5f ) / Fixed( 2 ) );
	// 	std::cout << "D: " << d << std::endl;

	// 	// Subtraction
	// 	Fixed e = a - b;
	// 	std::cout << "E: " << e << std::endl;
	// }
	// {
	// 	Fixed a( 1.0f );
	// 	Fixed b( 2.0f );
	// 	Fixed c = a + b;
	// 	Fixed d = a - b;
	// 	Fixed e = a * b;
	// 	Fixed f = a / b;
	// 	std::cout << "A: " << a << std::endl;
	// 	std::cout << "B: " << b << std::endl;
	// 	std::cout << "C: " << c << std::endl;
	// 	std::cout << "D: " << d << std::endl;
	// 	std::cout << "E: " << e << std::endl;
	// 	std::cout << "F: " << f << std::endl;
	// }
	// {
	// 	Fixed a(42 );
	// 	Fixed b( 42.42f );
	// 	std::cout << "A: " << a << std::endl;
	// 	std::cout << "B: " << b << std::endl;
	// 	try 
	// 	{
	// 		Fixed c( INT_MAX );
	// 		while (a.getRawBits() < INT_MAX)
	// 		{
	// 			a++;
	// 			std::cout << "A: " << a << std::endl;
	// 		}
	// 		std::cout << "A: " << ++a << std::endl;
	// 	}
	// 	catch (const std::overflow_error &e)
	// 	{
	// 		std::cerr << "Overflow error: " << e.what() << std::endl;
	// 		return 1;
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << "Exception: " << e.what() << std::endl;
	// 		return 1;
	// 	}
	// }
	{
		return 0;
	}
}