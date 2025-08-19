/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:59:09 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/19 11:17:45 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <stdexcept>

#include "../terminal_colors.hpp"

#define uint64_t unsigned long long

/**
 * @brief Checks if the given expression is subject valid.
 * @param expr The expression to check.
 * @return True if the expression is valid, false otherwise.
 */
bool isValidExpression(const std::string &expr)
{
	uint64_t numCount = 0;
	uint64_t opCount = 0;
	for (std::string::const_iterator it = expr.begin(); it != expr.end(); ++it)
	{
		if (std::isspace(*it))
			{continue;}
		if (std::isdigit(*it))
			{numCount++; continue;}
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			{opCount++; continue;}
	}
	if (numCount == 0 || opCount == 0)
		return false;
	if (numCount != opCount + 1) // there should be one more number than operators
		return false;
	return true;
}

/**
 * @brief Performs the calculation based on the top two operands and the operator.
 */
void	calculus_RPN(std::stack<int> &rpm)
{
	int	a;
	int b;
	int result;

	if (rpm.size() < 3)
		return ;
	char op = rpm.top();
	rpm.pop();			// remove operator;
	b = rpm.top();
	rpm.pop();			// remove first operand;
	a = rpm.top();
	rpm.pop();			// remove second operand;
	switch (op)			// do the calculus
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0) {
				throw std::runtime_error("Error: Division by zero.");}
			result = a / b;
			break;
	}
	rpm.push(result);	// push the result back onto the stack
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << TERMINAL_RED << "Usage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}
	std::string expr = argv[1];
	if (!isValidExpression(expr))
	{
		std::cerr << TERMINAL_RED << "Invalid expression. \n\
		Please make sure it only contains single-digit numbers and operators (+, -, *, /)." << std::endl;
		return 1;
	}

	std::stack<int> rpn;

	try {
		for (std::string::iterator it = expr.begin(); it != expr.end(); ++it)
		{
			if (std::isspace(*it))
				continue ;
			if (isdigit(*it))
				{rpn.push(*it - '0'); continue ;}
			if (!isdigit(*it))
				{rpn.push(*it); calculus_RPN(rpn);}
		}
	}
	catch (const std::exception &e)	{
		std::cerr << TERMINAL_RED << e.what() << std::endl; return 1;}

	if (rpn.size() == 1)
		std::cout << "Result: " << rpn.top() << std::endl;
	else
		std::cerr << TERMINAL_RED << "Error: Invalid RPN expression." << std::endl;
	return (0);
}
