/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainedAnimal.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:25:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/27 06:14:14 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINEDANIMAL_HPP
#define BRAINEDANIMAL_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class BrainedAnimal : public Animal
{
	private:										// Private members
		Brain *brain_base;
	protected:										// Protected members for inheritance
	
	public:
		BrainedAnimal();                                		// Default constructor
		BrainedAnimal(const BrainedAnimal &other);         		// Copy constructor
		BrainedAnimal &operator=(const BrainedAnimal &other);	// Assignment operator
		~BrainedAnimal();                                		// Destructor

		BrainedAnimal(const std::string &type_); // Constructor with type
		std::string getIdea(int index) const;
		void initializeIdeas(int power);
		Brain *getBrain() const; 
};

#endif // BRAINEDANIMAL_HPP
