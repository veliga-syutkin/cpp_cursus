/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:42:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 16:23:31 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include "../terminal_colors.hpp"
# include <iostream>

class Animal
{
	private:										// Private members

	protected:										// Protected members for inheritance
		std::string type;

	public:
		Animal();                                	// Default constructor
		Animal(const Animal &other);         	// Copy constructor
		Animal &operator=(const Animal &other); // Assignment operator
		virtual ~Animal();                                	// Destructor

		Animal(const std::string &type_);// Constructor with type
		virtual void makeSound() const;
		std::string getType() const;
};

#endif // ANIMAL_HPP
