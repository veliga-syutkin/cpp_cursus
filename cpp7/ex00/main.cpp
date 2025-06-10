/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:28:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/10 11:08:40 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

class Teste
{
	private:
		int _n;
	public:
		Teste(void):_n(0) {}
		Teste(int n):_n(n) {}
		bool operator==(Teste const &rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Teste const &rhs) const { return (this->_n != rhs._n); }
		bool operator>(Teste const &rhs) const { return (this->_n > rhs._n); }
		bool operator<(Teste const &rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Teste const &rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Teste const &rhs) const { return (this->_n <= rhs._n); }
		int get_n(void) const { return this->_n; }
};

std::ostream &operator<<(std::ostream &o, const Teste &a) {o << a.get_n(); return o;};

int	main( void )
{
	{
	int a = 2;
	int b = 3;

	::swap<int>( a, b );	// use `::` to call the global swap function instead of any potential local one
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << "\nrandom test from internet:" << std::endl;
	{
		Teste a(2);
		Teste b(4);

		::swap<Teste>(a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	return (0);
}
