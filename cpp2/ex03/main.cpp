/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:36:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 22:28:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <climits>

int main( void )
{
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 10);
	
		Point inside(2, 2);
		Point outside(20, 20);
		Point edge(5, 0);
		Point vertex(0, 0);
	
		std::cout << "Point inside triangle: " << bsp(a, b, c, inside) << std::endl;
		std::cout << "Point outside triangle: " << bsp(a, b, c, outside) << std::endl;
		std::cout << "Point on edge of triangle: " << bsp(a, b, c, edge) << std::endl;
		std::cout << "Point on vertex of triangle: " << bsp(a, b, c, vertex) << std::endl;
	}
	{
		return 0;
	}
}