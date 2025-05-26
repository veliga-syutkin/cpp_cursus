/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:00:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 17:42:46 by vsyutkin         ###   ########.fr       */
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
		void _initializeIdeas(); // Helper function to initialize ideas
	protected:										// Protected members for inheritance

	public:
		Brain();                                	// Default constructor
		Brain(const Brain &other);         	// Copy constructor
		Brain &operator=(const Brain &other); // Assignment operator
		~Brain();                                	// Destructor

		std::string getIdea(int index) const;
};

#endif // BRAIN_HPP
