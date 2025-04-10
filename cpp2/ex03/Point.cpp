/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:02:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 22:22:59 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
//	Canonical Orthodox Form

// Default constructor
Point::Point() : _x(0), _y(0)
{
	;
}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	;
}

// Assignment logic
Point &Point::operator=(const Point &other)
{
    if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
    }
    return *this;
}

// Destructor
Point::~Point()
{
	;
}

//############################################################################//
/* ************************************************************************** */
//	Private methods

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	;
}

Fixed Point::getX() const
{
	return _x;
}
Fixed Point::getY() const
{
	return _y;
}