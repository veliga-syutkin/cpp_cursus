/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:05:06 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/03 16:25:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <sstream>

// Constructor
Phonebook::Phonebook()
{
	_index = 0;
	for (int i = 0; i < 8; i++)
		_contacts[i] = Contact();
};

// Destructor
Phonebook::~Phonebook()
{
	// Destructor
};

/* ************************************************************************** */
// PRIVATE METHODS

void	Phonebook::pushIndex()
{
	if (_index++ == 7)
	{
		_index = 0;
		std::cout << "Phonebook is full." << std::endl; // Smol commentary, remember that this is a crappy software
	}
};

bool Phonebook::inputCheckerInt(std::string display, _PHONE_NUMBER &cell)
{
	std::string num;
	int i = 0;

	std::cout << display;
	std::getline(std::cin, num);
	while (num[i] && !std::cin.eof())
	{
		if (!std::cin.eof() && (!std::isdigit(num[i]) || i > 10))
		{
			std::cout << "Invalid input. Please enter a valid input: " << std::endl;
			return (false);
		}
		i++;
	}
	std::stringstream(num) >> cell;
	return (true);
};

void Phonebook::inputCheckerString(std::string display, std::string &str)
{
	std::cout << display;
	std::getline(std::cin, str);
	if (!std::cin.eof() && (str.empty() || !isprintable(str)))
	{
		std::cout << "Invalid input. Please enter a valid input: " << std::endl;
		inputCheckerString(display, str);
	}
}

// Check if the string is printable
// Returns true if all characters are printable
// Returns false if any character is not printable
bool	Phonebook::isprintable(std::string str)
{
	int cursor = 0;

	while (str[cursor])
	{
		if (!std::iswprint(str[cursor]) && !std::iswspace(str[cursor]))
			return (false);
		cursor++;	
	}
	return (true);
}

/* ************************************************************************** */
// PUBLIC METHODS

void Phonebook::addContact()
{
	// The order is like presented in the subject. Still crappy software, y'know? 
	std::string first;
	inputCheckerString("First name : ", first);

	std::string last;
	inputCheckerString("Last name : ", last);

	std::string nick;
	inputCheckerString("Nickname : ", nick);

	_PHONE_NUMBER phone = 0;
	while (!inputCheckerInt("Enter phone number: ", phone))
		;
	
	std::string secret;
	inputCheckerString("Darkest secret : ", secret);

	this->_contacts[this->_index].setContact(first, last, nick, phone, secret);
	std::cout << "Contact added!" << std::endl;
	std::cout << std::endl;
	pushIndex();
}

void	Phonebook::searchContact()
{
	int	i = -1;
	std::string input;

	while (++i < 8)
		_contacts[i].DisplaySearch(i + 1);
	std::cout << "Enter the index (1-8) of the contact you want to see: " << std::endl;
	i = 0;
	while (!i || i == 9)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (std::isdigit(input[0]) && input.length() == 1)
			std::stringstream(input) >> i;
		else
			i = 0;
		if (i <= 0 || i > 8)
			std::cout << "Enter the index (1-8) of the contact you want to see: " << std::endl;
		else
		{
			std::cout << "Contact " << i << ":" << std::endl;
			_contacts[i - 1].Display();
		}
	}
}
