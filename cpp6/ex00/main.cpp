/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:03:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/04 16:26:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (argc > 2)
			std::cout << "Argument " << i << ": ";
		try
		{
			ScalarConverter::convert(argv[i]);
		}
		catch (const ScalarConverterException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
