/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:42:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 21:07:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include "../terminal_colors.hpp"
# include <iostream>
# include <cstdlib>

class Animal
{
	private:										// Private members

	protected:										// Protected members for inheritance
		std::string type;
	public:
		Animal();                                	// Default constructor
		Animal(const Animal &other);         	// Copy constructor
		Animal &operator=(const Animal &other); // Assignment operator
		virtual ~Animal();                      // Destructor. Is virtual to allow derived classes to override it. Automatically all derived classe have their destructor virtual, so no need to specify it in derived classes.

		Animal(const std::string &type_);		// Constructor with type
		virtual void makeSound() const;
		std::string getType() const;
};

#endif // ANIMAL_HPP
