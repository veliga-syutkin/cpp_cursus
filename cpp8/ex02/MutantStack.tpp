/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:50:56 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/10 09:55:08 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ########################################################################## */

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() 
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &source) : std::stack<T>(source) 
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &source)
{
	std::cout << "MutantStack assignment operator called" << std::endl;
	if (this != &source)
		std::stack<T>::operator=(source);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
}

/* ########################################################################## */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) 
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

/* ************************************************************************** */

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void)	const
{
	return (this->c.end());
}

/* ************************************************************************** */

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void) 
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)   
{
	return (this->c.rend());
}

/* ************************************************************************** */

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const 
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}