/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:30:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/08 16:01:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

// Constructor
Harl::Harl(void)
{
	this->Functions[0] = &Harl::debug;
	this->Functions[1] = &Harl::info;
	this->Functions[2] = &Harl::warning;
	this->Functions[3] = &Harl::error;
}

// Destructor
Harl::~Harl()
{
	;
}

/* ************************************************************************** */
// Private methods
void Harl:: debug(void)
{
	std::cout << MSG_DEBUG << std::endl;
};

void Harl:: info(void)
{
	std::cout << MSG_INFO << std::endl;
};

void Harl:: warning(void)
{
	std::cout << MSG_WARNING << std::endl;
};

void Harl:: error(void)
{
	std::cout << MSG_ERROR << std::endl;
};

/* ************************************************************************** */
// Public methods

void Harl:: complain(std::string level)
{
	std::string strings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i)
	{
		if (level == strings[i])
		{
			(this->*Functions[i])();
			return ;
		};
	}
	std::cout << MSG_EMPTY << std::endl;
}
