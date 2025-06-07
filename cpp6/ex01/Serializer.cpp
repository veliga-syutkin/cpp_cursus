/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:38:57 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 16:57:13 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Serializer::Serializer()
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Serializer called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
	(void)other; // Avoid unused parameter warning
	std::cout << TERMINAL_GREEN << "\tCopy constructor Serializer called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		std::cout << TERMINAL_GREEN << "\tAssignation operator Serializer called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Serializer::~Serializer()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Serializer called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw;
	if (!ptr)
	{
		std::cerr << TERMINAL_RED << "Error: Attempt to serialize a null pointer." << TERMINAL_RESET << std::endl;
		return (0);
	}
	std::cout << TERMINAL_YELLOW << "Serializing data: " << ptr << TERMINAL_RESET << std::endl;
	raw = reinterpret_cast<uintptr_t>(ptr);
	ptr = NULL; // Set pointer to NULL after serialization
	std ::cout << TERMINAL_YELLOW << "Data serialized to raw: " << raw << TERMINAL_RESET << std::endl;
	std::cout << TERMINAL_YELLOW << "Pointer after serialization: " << ptr << TERMINAL_RESET << std::endl;
	return (raw);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
	{
		std::cerr << TERMINAL_RED << "Error: Attempt to deserialize a null pointer." << TERMINAL_RESET << std::endl;
		return (NULL);
	}
	std::cout << TERMINAL_YELLOW << "Deserializing data..." << TERMINAL_RESET << std::endl;
	Data *data = reinterpret_cast<Data *>(raw);
	if (!data)
	{
		std::cerr << TERMINAL_RED << "Error: Deserialization failed, raw data is invalid." << TERMINAL_RESET << std::endl;
		return (NULL);
	}
	std::cout << TERMINAL_YELLOW << "Data deserialized from raw: " << raw << TERMINAL_RESET << std::endl;
	std::cout << TERMINAL_YELLOW << "Pointer after deserialization: " << data << TERMINAL_RESET << std::endl;
	return (reinterpret_cast<Data *>(raw));
}