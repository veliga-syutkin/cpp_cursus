/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/26 15:35:19 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		WrongCat();                                	// Default constructor
		WrongCat(const WrongCat &other);         	// Copy constructor
		WrongCat &operator=(const WrongCat &other); // Assignment operator
		~WrongCat();                                	// Destructor

		void makeSound() const; 					// Override* makeSound method
};

/*

* - in this case, the `makeSound` method from WrongAnimal is not virtual, so `makeSound` from WrongCat Does NOT override the base class method.

*/

#endif // WRONGCAT_HPP
