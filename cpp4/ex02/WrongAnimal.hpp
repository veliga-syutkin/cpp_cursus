/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/26 15:35:19 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include "../terminal_colors.hpp"
# include <iostream>

class WrongAnimal
{
	private:										// Private members

	protected:										// Protected members for inheritance
		std::string type;

	public:
		WrongAnimal();                                	// Default constructor
		WrongAnimal(const WrongAnimal &other);         	// Copy constructor
		WrongAnimal &operator=(const WrongAnimal &other); // Assignment operator
		virtual ~WrongAnimal();                                	// Destructor

		WrongAnimal(const std::string &type_); // Constructor with type
		virtual void makeSound() const;
		std::string getType() const;
};

#endif // WRONGANIMAL_HPP
