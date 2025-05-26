/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/26 15:35:19 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# define BARK "@@@  @@@  @@@  @@@@@@  @@@@@@@@ @@@\n\
@@!  @@!  @@! @@!  @@@ @@!      @@@\n\
@!!  !!@  @!@ @!@!@!@! @!!!:!   !@!\n\
 !:  !!:  !!  !!:  !!! !!:         \n\
  ::.:  :::    :   : :  :       :.:\n\
"

class Dog : public Animal
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		Dog();                                	// Default constructor
		Dog(const Dog &other);         	// Copy constructor
		Dog &operator=(const Dog &other); // Assignment operator
		~Dog();                                	// Destructor

		void makeSound() const; //override; // good practice to use override keyword (C++11 and later) to indicate that this method overrides a virtual method from the base class
};

#endif // DOG_HPP
