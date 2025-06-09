/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:09:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/09 13:31:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	std::cout << TERMINAL_BOLD_YELLOW << "=== Span ===" << TERMINAL_RESET << std::endl;
	std::cout << TERMINAL_CYAN << "`main` from the subject:" << TERMINAL_RESET << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << '\n' << TERMINAL_BOLD_GREEN << "Custom tests" << TERMINAL_RESET << std::endl;
	{
		Span sp = Span(10);
		int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		sp.addNumber(numbers, 10); // Add the array of numbers

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(11); // This should throw an exception
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try
		{
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
	}
	std::cout << '\n' << TERMINAL_MAGENTA << "Exceptions tests" << TERMINAL_RESET << std::endl;
	{
		Span sp;
		int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		try 
		{
			sp.addNumber(1);
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try 
		{
			sp.addNumber(numbers, 10);
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try 
		{
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try 
		{
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}

		Span span(1);
		try 
		{
			span.addNumber(1);
			span.addNumber(2); // This should throw an exception
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try 
		{
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try 
		{
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
		try 
		{
			span.addNumber(numbers, 10); // This should throw an exception
		}
		catch (const SpanException &e)
		{
			std::cerr << TERMINAL_RED << "Exception: " << e.what() << TERMINAL_RESET << std::endl;
		}
	}
	return (0);
}