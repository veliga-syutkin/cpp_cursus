/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:39:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 16:55:57 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include "../terminal_colors.hpp"
# include <iostream> 

typedef unsigned long uintptr_t; // Define uintptr_t bc fuk c++98 restriction

typedef struct Data
{
	int			integer;
	std::string	str;
} Data;

class Serializer
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		Serializer();                                	// Default constructor
		Serializer(const Serializer &other);         	// Copy constructor
		Serializer &operator=(const Serializer &other); // Assignment operator
		~Serializer();                                	// Destructor

		static uintptr_t serialize(Data *ptr);

		static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
