/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 10:09:23 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "../terminal_colors.hpp"

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
};

#endif // FIXED_HPP
