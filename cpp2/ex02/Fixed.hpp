/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/11 00:37:00 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "../terminal_colors.hpp"
#include <iostream>

# define MSG_ERR_ADD "\tAddition: value out of range"
# define MSG_ERR_SUB "\tSubtraction: value out of range"
# define MSG_ERR_MUL "\tMultiplication: value out of range"
# define MSG_ERR_DIV "\tDivision: value out of range"

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

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++(); // Pre-increment
	Fixed operator++(int); // Post-increment
	Fixed &operator--(); // Pre-decrement
	Fixed operator--(int); // Post-decrement

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif // FIXED_HPP
