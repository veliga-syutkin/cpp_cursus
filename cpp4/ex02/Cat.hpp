/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/26 15:35:19 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "BrainedAnimal.hpp"

# define MEOW "\
:::=======  :::===== :::====  :::  ===  === === ==\n\
::: === === :::      :::  === :::  ===  === = === \n\
=== === === ======   ===  === ===  ===  ===       \n\
===     === ===      ===  ===  ===========        \n\
===     === ========  ======    ==== ====         \n\
"

class Cat : public BrainedAnimal
{
	private:										// Private members
		Brain *brain;
		void _catIdeas();
	protected:										// Protected members for inheritance

	public:
		Cat();                                	// Default constructor
		Cat(const Cat &other);         	// Copy constructor
		Cat &operator=(const Cat &other); // Assignment operator
		~Cat();                                	// Destructor

		void makeSound() const; // override; // good practice to use override keyword (only in c++11 and later)
};

#endif // CAT_HPP
