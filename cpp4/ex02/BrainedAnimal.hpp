/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainedAnimal.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:25:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 21:14:33 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINEDANIMAL_HPP
#define BRAINEDANIMAL_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class BrainedAnimal : public Animal
{
	private:										// Private members

	protected:										// Protected members for inheritance
		Brain *brain;
	public:
		BrainedAnimal();                                		// Default constructor
		BrainedAnimal(const BrainedAnimal &other);         		// Copy constructor
		BrainedAnimal &operator=(const BrainedAnimal &other);	// Assignment operator
		~BrainedAnimal();                                		// Destructor

		BrainedAnimal(const std::string &type_); // Constructor with type
		std::string getIdea(int index) const;
		std::string getType() const; // override; 
		void initializeIdeas(int power);
};

#endif // BRAINEDANIMAL_HPP
