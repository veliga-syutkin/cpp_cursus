/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:32 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 15:26:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include "../terminal_colors.hpp"
# include "ExceptionsCPP5.hpp"
# include <iostream>
# include <ostream>

# define MIN_CLASSIFIED_GRADE 0
# define MAX_CLASSIFIED_GRADE 149

class Bureaucrat
{
	private:										// Private members
		const std::string	_name;
		short int			_grade;					// between 1-150; lowest number = highest grade
		short int			_gradeClassified;		// between 0-149; highest number = highest grade

	protected:										// Protected members for inheritance

	public:
		Bureaucrat();                                	// Default constructor
		Bureaucrat(const Bureaucrat &other);         	// Copy constructor
		Bureaucrat &operator=(const Bureaucrat &other); // Assignment operator
		~Bureaucrat();                                	// Destructor

		Bureaucrat(const std::string &name, short unsigned int grade);

		const std::string &getName() const;
		const short int &getGrade() const;

		void	promote();
		void	demote();
	};
	
std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP
