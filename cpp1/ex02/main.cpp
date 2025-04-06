/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:32:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 17:38:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include <iomanip>

#define MEM_VAR "The memory address of the string variable "
#define MEM_PTR "The memory address held by stringPTR "
#define MEM_REF "The memory address held by stringREF "

#define VAL_STR "The value of the string variable "
#define VAL_PTR "The value pointed to by stringPTR "
#define VAL_REF "The value pointed to by stringREF "


/*
Once there was a small kingdom, ruled by 5 brothers. 
Each important decision was voted by all of them. 
But not every time they could reunite; 
And in order to make a decision,
One could give his vote to an representative.

At one point, they decided to make a vote about the color of the castle.
For the such (un)important decision, only 2 of them were present,
While there were 2 other people representing the missing 3 brothers.
One was REF, the other was PTR.
The REF represented only the 3rd brother. [REF acts like an alias]
The PTR represented the 4th and then the 5th. [PTR is reassignable]
Once all votes submitted and counted, 
The REF came back to represented 3rd brother and told him the results. [how REF works]
The PTR, however, was lost because he didn't know who he was representing anymore. [NULL aka nullptr]
This is why, in the kingdom of programming, the REF is trusted for its loyalty, while the PTR, though versatile, must be handled with care to avoid confusion or chaos.
*/
int main()
{
	std::string skull = "HI THIS IS BRAIN";

	std::string *stringPTR = &skull;
	std::string &stringREF = skull;

	std::cout << std::right << std::setw(80) << MEM_VAR << &skull << std::endl;
	std::cout << std::right << std::setw(80) << MEM_PTR << stringPTR << std::endl;
	std::cout << std::right << std::setw(80) << MEM_REF << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << std::right << std::setw(80) << VAL_STR << skull << std::endl;
	std::cout << std::right << std::setw(80) << VAL_PTR << *stringPTR << std::endl;
	std::cout << std::right << std::setw(80) << VAL_REF << stringREF << std::endl;
}
