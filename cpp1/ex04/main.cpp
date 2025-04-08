/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:59:06 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/08 19:07:55 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define TERMINAL_RESET "\033[0m"
#define TERMINAL_RED "\033[31m"

int	main(int argc, char **argv)
{
	if (argc != 4 || argv[2][0] == '\0') /* we can't replace a string containing only null terminator, 
											since all strings are terminated by null terminator duh*/
	{
		std::cerr << TERMINAL_RED << "Check syntax! \n /path/to/file string_to_find_and_remplace string_replace_with" << TERMINAL_RESET << std::endl;
		return (EXIT_FAILURE);
	}
	std::fstream infile(argv[1], std::fstream::in);
	if (!infile.is_open())
	{
		std::cerr << "Couldn't open file" << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}
	std::string outputFileName = std::string(argv[1]).append(".replace");
	std::ofstream outfile(outputFileName.c_str(), std::fstream::out);
	if (!outfile.is_open())
	{
		std::cerr << "Couldn't open/create file" << argv[1] << ".replace" << std::endl;
		infile.close();
		return (EXIT_FAILURE);
	}
	std::string buffer;
	std::size_t found;
	std::size_t cursor;
	while (std::getline(infile, buffer, '\n'))
	{
		cursor = 0;
		found = 0;
		while (found != std::string::npos)
		{
			found = buffer.find(argv[2], found);
			// std::cout << "[DEBUG] found at index:" << found << std::endl;
			if (found != std::string::npos)
			{
				// std::cout << "[DEBUG] substr:" << buffer.substr(cursor, (found - cursor)) << std::endl;
				outfile << buffer.substr(cursor, (found - cursor)) << argv[3]; // copy the initial string and replace relevant string with new string
				cursor = found + std::string(argv[2]).length(); // move cursor at the end of just replaced string
				// std::cout << "[DEBUG] cursor at index:" << cursor << std::endl;
				found = cursor;
			}
			else
				outfile << buffer.substr(cursor); // copy the rest initial string
			}
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (EXIT_SUCCESS);
}
