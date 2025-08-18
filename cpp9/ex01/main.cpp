/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:59:09 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/19 00:13:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

#define uint64_t unsigned long long

/**
 * @brief Checks if the given expression is subject valid.
 * @param expr The expression to check.
 * @return True if the expression is valid, false otherwise.
 */
bool isValidExpression(std::string &expr)
{
	uint64_t cursor = 0;
	for (std::string::iterator it = expr.begin(); it != expr.end(); ++it)
	{
		if (std::isspace(*it))
			continue;
		if ((cursor == 0 || cursor == 1))
			{if (!std::isdigit(*it))
				return false;}
		else if (cursor % 2 == 0 && *it != '+' && *it != '-' && *it != '*' && *it != '/')
			return false;
		else if (cursor % 2 == 1 && !std::isdigit(*it))
			return false;
		cursor++;
	}
	return true;
}

int	calculus_RPN(std::stack<int> &rpm)
{
	int	a;
	int b;
	int result;

	while (rpm.size() > 1)
	{
		a = rpm.top() - '0'; // Convert char to int
		rpm.pop();
		b = rpm.top() - '0'; // Convert char to int
		rpm.pop();
		switch (rpm.top())
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
				result = a / b;
				break;
		}
		rpm.pop();
		rpm.push(result + '0'); // Convert int back to char to calculate the next operation
	}
	return rpm.top() - '0'; // Convert char back to int and return it
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}
	std::string expr = argv[1];
	if (!isValidExpression(expr))
	{
		std::cerr << "Invalid expression. \n\
		Please make sure it only contains single-digit numbers and operators (+, -, *, /)." << std::endl;
		return 1;
	}

	std::stack<int> rpn;

	for (std::string::reverse_iterator it = expr.rbegin(); it != expr.rend(); ++it)
	{
		if (*it != ' ')
		{	rpn.push(*it);
			// std::cout << "[DEBUG] Pushing: " << *it << std::endl; // Debug output
	}}
	
	std::cout << "Result: " << calculus_RPN(rpn) << std::endl;
	return (0);
}
