/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:26:25 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/03 16:27:10 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	try
	{

	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (1);
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred." << std::endl;
		return (1);
	}
}