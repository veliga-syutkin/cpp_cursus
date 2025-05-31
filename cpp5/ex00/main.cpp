/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:40:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/31 13:14:31 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(0));
	{
		std::cout << "Normal behaviour:" << std::endl;
		try
		{
			Bureaucrat nameless;
			std::cout << nameless << std::endl;
		}
		catch (const ExceptionsCPP5 &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try
		{
			Bureaucrat	promotion("Perspective Bureaucrat", (short)(std::rand() % (150 - 2 + 1) + 2));
			Bureaucrat	demotion("Demoted Bureaucrat", (short)(std::rand() % (150 - 2 + 1) + 1));
			std::cout << promotion << std::endl;
			promotion.promote();
			std::cout << "After promotion: " << promotion << std::endl;
			std::cout << demotion << std::endl;
			demotion.demote();
			std::cout << "After demotion: " << demotion << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << TERMINAL_BOLD_GREEN << "\n\n\t\t\tException behaviour:" << TERMINAL_RESET << std::endl;
		try
		{
			Bureaucrat invalidGrade("Invalid Grade Bureaucrat", 0); // Invalid grade, should throw an exception
		}
		catch(const BureaucratGradeTooHighException & e)
		{
			std::cout << "exception caught: Too High Grade Bureaucrat" << std::endl;
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat invalidGrade("Invalid Grade Bureaucrat", 151); // Invalid grade, should throw an exception
		}
		catch(const BureaucratGradeTooLowException & e)
		{
			std::cout << "exception caught: Too Low Grade Bureaucrat" << std::endl;
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat generalissimo("Generalissimo", 1); // Highest grade, should not throw an exception
			std::cout << generalissimo << std::endl;
			generalissimo.promote(); // Should throw an exception
		}
		catch(const BureaucratGradeTooHighException & e)
		{
			std::cout << "exception caught: Too High Grade Bureaucrat" << std::endl;
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat Private("Private", 150); // Lowest grade, should not throw an exception
			std::cout << Private << std::endl;
			Private.demote(); // Should throw an exception
		}
		catch(const BureaucratGradeTooLowException & e)
		{
			std::cout << "exception caught: Too Low Grade Bureaucrat" << std::endl;
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat invalidGrade("Invalid Grade Bureaucrat", 0); // Invalid grade, should throw an exception
		}
		catch(const BureaucratGradeTooLowException & e) // Handling exceptions that are out of scope of this catch!
		{
			std::cout << "exception caught: Too High Grade Bureaucrat" << std::endl;
			std::cerr << e.what() << '\n';
		}
		catch (...)
		{
			std::cout << "expected: exception caught: Unknown exception" << std::endl;
		}
	}
}