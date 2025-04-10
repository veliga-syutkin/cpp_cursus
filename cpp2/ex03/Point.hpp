/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:02:23 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 22:27:35 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:										// Private members
		Fixed _x;
		Fixed _y;

	protected:										// Protected members for inheritance

	public:
		Point();                                	// Default constructor
		Point(const Point &other);            	// Copy constructor
		Point &operator=(const Point &other); 	// Assignment operator
		~Point();                               	// Destructor
	
		Point(const float x, const float y);

		Fixed getX() const;			// Getter for x
		Fixed getY() const;			// Getter for y
};	

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
