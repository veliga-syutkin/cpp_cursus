/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 15:05:07 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "../terminal_colors.hpp"
#include <iostream>

class Fixed {
private:
	int _value;
	static const int _frac_bits = 8;
	
	protected:
    // Protected members for inheritance
	
	public:
    Fixed();                                 // Default constructor
    Fixed(const Fixed &other);             // Copy constructor
    Fixed &operator=(const Fixed &other);  // Assignment operator
    ~Fixed();                                // Destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int value);
	Fixed(const float value);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif // FIXED_HPP
