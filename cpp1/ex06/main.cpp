/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/08 18:54:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl BigSmoke;
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}
	// BigSmoke.complain("no");
	char *level = argv[1];
	for (int i = 0; i < 5; i++)
	{
		if (level == BigSmoke.cry[i])
		{
			switch (i)
			{
				case 0:
					BigSmoke.complain("DEBUG");
					// fall through
				case 1:
					BigSmoke.complain("INFO");
					// fall through
				case 2:
					BigSmoke.complain("WARNING");
					// fall through
				case 3:
					BigSmoke.complain("ERROR");
					break;
			}
			return (0);
		}
	}
	BigSmoke.complain("");
}
