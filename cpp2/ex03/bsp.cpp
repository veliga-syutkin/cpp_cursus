/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:04:50 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 22:49:58 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static Fixed calculateArea(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed tmp = ((p1.getX() * (p2.getY() - p3.getY()) +
            p2.getX() * (p3.getY() - p1.getY()) +
            p3.getX() * (p1.getY() - p2.getY())));
	if (tmp < 0)
		tmp = Fixed (-1) * tmp;
	return (tmp);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = (calculateArea(a, b, c));
    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);

    // Vérifiez si la somme des sous-aires est égale à l'aire totale
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false); 
    return (totalArea == (area1 + area2 + area3));
}
