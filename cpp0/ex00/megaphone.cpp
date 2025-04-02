/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:40:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/01 09:47:16 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	swapCase(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		else if (std::isupper(str[i]))
			str[i] = std::tolower(str[i]);
	}
}

void	mockingCase(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (i % 2 == 0)
			str[i] = std::tolower(str[i]);
		else
			str[i] = std::toupper(str[i]);
	}
}

void	megaphone(char *str)
{
	for (int i = 0; str[i]; i++)
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
}


int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < argc; i++)
	{
		mockingCase(argv[i]);
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	return (0);
}
