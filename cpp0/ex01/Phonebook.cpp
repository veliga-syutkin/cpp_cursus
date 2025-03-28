/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:05:06 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/28 22:05:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>

/* ************************************************************************** */
// PRIVATE METHODS

void	Phonebook::pushIndex()
{
	if (_index == 8)
	{
		_index = 0;
		std::cout << "Phonebook is full." << std::endl; // Smol commentary, remember that this is a crappy software
	}
	else
		_index++;
};

void Phonebook::inputCheckerString(std::string display, std::string cell)
{
	std::cout << display;
	while (!(std::cin >> cell))
	{
		std::cout << "Invalid input. Please enter a valid input: ";
		std::cin.clear(); // clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid input
	}
};

void Phonebook::inputCheckerInt(std::string display, uint32_t cell)
{
	std::cout << display;
	while (!(std::cin >> cell))
	{
		std::cout << "Invalid input. Please enter a valid input: ";
		std::cin.clear(); // clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid input
	}
};

/* ************************************************************************** */
// PUBLIC METHODS

void Phonebook::addContact()
{
	std::string first;
	std::string last;
	std::string nick;
	std::string secret;
	u_int32_t phone;

// Since it's crappy software, using `cin` only instead of `getline` (or better!)
// The order is like presented in the subject. Still crappy software, y'know? 

	inputCheckerString("Enter first name: ", first);
	inputCheckerString("Enter last name: ", last);
	inputCheckerString("Enter nickname: ", nick);
	inputCheckerInt("Enter phone number: ", phone);
	inputCheckerString("Enter darkest secret: ", secret);

	_contacts[_index].setFirst(first);
	_contacts[_index].setLast(last);
	_contacts[_index].setNick(nick);
	_contacts[_index].setPhone(phone);
	_contacts[_index].setSecret(secret);
	pushIndex();
}
