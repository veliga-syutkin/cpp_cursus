/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:20:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/28 20:59:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Methods, setters and getters
#include "Contact.hpp"

/* ************************************************************************** */
// PRIVATE METHODS

// void	Contact::setChar(std::string dest, const char *str)
// {
// 	dest = strdup(str);
// };

// void Contact::setFirst(const char *first)
// {
// 	setChar(_first, first);
// };

// void Contact::setLast(const char *last)
// {
// 	setChar(_last, last);
// };

// void Contact::setNick(const char *nick)
// {
// 	setChar(_nick, nick);
// };

// void Contact::setSecret(const char *secret)
// {
// 	setChar(_secret, secret);
// };

// void Contact::setPhone(const char *phone)
// {
// 	int	tmp = -1;

// 	if (strlen(phone) > 10)
// 	{
// 		std::cerr << "Phone number is too long" << std::endl;
// 		return;
// 	}
// 	tmp = atoi(phone);
// 	if (tmp == 0 && tmp[0] != '0')
// 	{
// 		std::cerr << "Phone number is invalid" << std::endl;
// 		return;
// 	}
// 	_phone = tmp;
// };

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

void Contact::DisplaySearch()
{
	std::cout 
		<< std::right << std::setw(10) << _first << "|" 
		<< std::right << std::setw(10) << _last << "|" 
		<< std::right << std::setw(10) << _nick << std::endl;
};
