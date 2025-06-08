/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:40:50 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/08 14:40:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Array called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		if (this->_size == 0)
		{
			this->_data = NULL;
		}
		else
		{
			this->_data = new T[_size];
			for (std::size_t i = 0; i < _size; ++i)
			{
				this->_data[i] = other._data[i];
			}
		}
	}
	std::cout << TERMINAL_GREEN << "\tCopy constructor Array called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (this->_data != NULL)
		{
			delete[] _data;
		}
		this->_size = other._size;
		if (this->_size == 0)
		{
			this->_data = NULL;
		}
		else
		{
			this->_data = new T[_size];
			for (std::size_t i = 0; i < _size; ++i)
			{
				this->_data[i] = other._data[i];
			}
		}
		std::cout << TERMINAL_GREEN << "\tAssignation operator Array called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	if (this->_data != NULL)
	{
		delete[] this->_data;
		this->_data = NULL;
	}
	this->_size = 0;
	std::cout << TERMINAL_GREEN << "\tDestructor Array called" << TERMINAL_RESET << std::endl;
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

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n == 0)
	{
		_data = NULL;
	}
	else
	{
		_data = new T[n];
	}
	std::cout << TERMINAL_GREEN << "\tConstructor Array with size " << n << " called" << TERMINAL_RESET << std::endl;
}

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of range");
	}
	return _data[index];
}

template <typename T>
const T &Array<T>::operator[](std::size_t index) const
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of range");
	}
	return _data[index];
}

template <typename T>
std::size_t Array<T>::size() const
{
	return _size;
}
