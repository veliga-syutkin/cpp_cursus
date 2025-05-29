/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:40:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/30 01:38:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Intern.hpp"

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
			PresidentialPardonForm nameless1;
			std::cout << nameless1 << std::endl;
			RobotomyRequestForm nameless2;
			std::cout << nameless2 << std::endl;
			ShrubberyCreationForm nameless3;
			std::cout << nameless3 << std::endl;
		}
		catch (const ExceptionsCPP5 &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		std::cout << TERMINAL_BG_RED << "Signing form test:" << TERMINAL_RESET << std::endl;
		try
		{
			Bureaucrat	seventy("seventy", 70);
			PresidentialPardonForm presidentialForm("President");
			RobotomyRequestForm robotomyForm("Robot");
			ShrubberyCreationForm shrubberyForm("Garden");
			std::cout << presidentialForm << std::endl;
			std::cout << robotomyForm << std::endl;
			std::cout << shrubberyForm << std::endl;
			seventy.signForm(robotomyForm); // Should succeed
			seventy.signForm(shrubberyForm); // Should succeed
			seventy.signForm(presidentialForm); // Should fail, no enough grade
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << TERMINAL_BG_RED << "Executing form test:" << TERMINAL_RESET << std::endl;
		try
		{
			Bureaucrat	CEO("CEO", 1);
			Bureaucrat	seventy("seventy", 70);
			PresidentialPardonForm presidentialForm("President");
			RobotomyRequestForm robotomyForm("Robot");
			ShrubberyCreationForm shrubberyForm("Garden");
			CEO.signForm(robotomyForm); // Should succeed
			CEO.signForm(shrubberyForm); // Should succeed
			CEO.signForm(presidentialForm); // Should fail
			std::cout << presidentialForm << std::endl;
			std::cout << robotomyForm << std::endl;
			std::cout << shrubberyForm << std::endl;
			seventy.executeForm(shrubberyForm);
			seventy.executeForm(robotomyForm); // Should fail, no enough grade
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << TERMINAL_BG_RED << "Executing not signed form test:" << TERMINAL_RESET << std::endl;
		try
		{
			Bureaucrat	CEO("CEO", 1);
			PresidentialPardonForm presidentialForm("President");
			CEO.executeForm(presidentialForm); // Should fail, not signed
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void	default_intern_test()
{
	std::cout << TERMINAL_BG_BLUE << "Intern test:" << TERMINAL_RESET << std::endl;
	try
	{
		Intern intern;
		AForm *form1 = intern.makeForm("robotomy request", "Bender");
		AForm *form2 = intern.makeForm("shrubbery creation", "Garden");
		AForm *form3 = intern.makeForm("presidential pardon", "President");
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		delete form1;
		delete form2;
		delete form3;
	}
	catch (const ExceptionsCPP5 &e)
	{
		std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
	}
}

int	main(void)
{
	std::srand(std::time(0));
	default_bureaucrat_test();
	default_form_test();
	default_intern_test();
}