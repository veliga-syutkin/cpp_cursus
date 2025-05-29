/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:40:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 17:09:35 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

void	default_bureaucrat_test()
{
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
		catch(const BureaucratGradeTooLowException & e)
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

void	default_form_test()
{
	{
		std::cout << TERMINAL_BG_RED << "Normal Form behaviour:" << TERMINAL_RESET << std::endl;
		try
		{
			Form nameless;
			std::cout << nameless << std::endl;
		}
		catch (const ExceptionsCPP5 &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try
		{
			Bureaucrat	hundred("Hundred", 100);
			Bureaucrat	fifty("Fifty", 50);
			Form		sixty_nine("Sixty Nine", 69, 69);
			std::cout << "Created: " << sixty_nine << std::endl;
			std::cout << fifty << "Signs " << sixty_nine.getName() << std::endl;
			fifty.signForm(sixty_nine); // Should succeed
			std::cout << "Form signed: " << sixty_nine.isSigned() << std::endl;
			std::cout << hundred << "Tries to sign " << sixty_nine.getName() << std::endl;
			hundred.signForm(sixty_nine); // Should fail
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int	main(void)
{
	std::srand(std::time(0));
	default_bureaucrat_test();
	default_form_test();
}