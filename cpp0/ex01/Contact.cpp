/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:20:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/28 19:01:03 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Methods, setters and getters
#include "Contact.hpp"

/* ************************************************************************** */
// PRIVATE METHODS

void	Contact::setChar(char *dest, const char *str)
{
	dest[10] = '\0';
	if (strlen(str) > 10)
	{
		strncpy(dest, str, 9);
		dest[9] = '.';
	}
	else
		strncpy(dest, str, 10);
};

void Contact::setFirst(const char *first)
{
	setChar(_first, first);
};

void Contact::setLast(const char *last)
{
	setChar(_last, last);
};

void Contact::setNick(const char *nick)
{
	setChar(_nick, nick);
};

void Contact::setSecret(const char *secret)
{
	setChar(_secret, secret);
};

void Contact::setPhone(const char *phone)
{
	if (strlen(phone) > 10)
	{
		std::cerr << "Phone number is too long" << std::endl;
		return;
	}
	_phone = atoi(phone);
	if (_phone == 0 && phone[0] != '0')
	{
		std::cerr << "Phone number is invalid" << std::endl;
		return;
	}
};

/* ************************************************************************** */
// PUBLIC METHODS

void Contact::Display()
{
	std::cout << "First name: " << _first << std::endl;
	std::cout << "Last name: " << _last << std::endl;
	std::cout << "Nickname: " << _nick << std::endl;
	std::cout << "Phone number: " << _phone << std::endl;
	std::cout << "Darkest secret: " << _secret << std::endl;
};

// void Contact::DisplaySearch()
// {
// 	std::cout << std::setw(10) << _first << "|";
// 	std::cout << std::setw(10) << _last << "|";
// 	std::cout << std::setw(10) << _nick << "|" << std::endl;
// };