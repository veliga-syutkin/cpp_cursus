/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:00:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 21:08:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include "../terminal_colors.hpp"
# include <iostream>

class Brain
{
	private:										// Private members
		std::string _ideas[100];
	 
	protected:										// Protected members for inheritance
		
	public:
		Brain();                                	// Default constructor
		Brain(const Brain &other);         			// Copy constructor
		Brain &operator=(const Brain &other); 		// Assignment operator
		~Brain();                                	// Destructor
		
		std::string getIdea(int index) const;
		void initializeIdeas(int power); 			// Helper function to initialize ideas
};

#endif // BRAIN_HPP
