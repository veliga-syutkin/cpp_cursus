/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:32:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>

#define MEM_VAR "The memory address of the string variable "
#define MEM_PTR "The memory address held by stringPTR "
#define MEM_REF "The memory address held by stringREF "

#define VAL_STR "The value of the string variable "
#define VAL_PTR "The value pointed to by stringPTR "
#define VAL_REF "The value pointed to by stringREF "

int main()
{
	std::string skull = "HI THIS IS BRAIN";

	std::string *stringPTR = &skull;
	std::string &stringREF = skull;

	std::cout << MEM_VAR << skull << std::endl;
	std::cout << MEM_PTR << stringPTR << std::endl;
	std::cout << MEM_REF << stringREF << std::endl;
	std::cout << std::endl;

	std::cout << VAL_STR << skull << std::endl;
	std::cout << VAL_PTR << *stringPTR << std::endl;
	std::cout << VAL_REF << stringREF << std::endl;
}
