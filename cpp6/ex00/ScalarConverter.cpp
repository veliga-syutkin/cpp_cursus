/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:34:48 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 16:34:51 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Static member initialization
long ScalarConverter::_int = 0;
double ScalarConverter::_double = 0.0;
bool ScalarConverter::_overflowedInt = false;
bool ScalarConverter::_isSpecial = false;

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor ScalarConverter called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	(void)other; // Avoid unused parameter warning
	std::cout << TERMINAL_GREEN << "\tCopy constructor ScalarConverter called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this != &other)
	{
		std::cout << TERMINAL_GREEN << "\tAssignation operator ScalarConverter called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << TERMINAL_GREEN << "\tDestructor ScalarConverter called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

// Converts from the string to integer with checks for overflows of limits of int.
int	ScalarConverter::ft_strtoi(const std::string &value)
{
	long	integer;

	errno = 0; // Reset errno before conversion
	integer = static_cast<long>(strtol(value.c_str(), NULL, 10));
	if (errno == ERANGE || integer > INT_MAX || integer < INT_MIN) // errno checks for long_overflow
	{
		_overflowedInt = true; // Set overflowedInt to true if the conversion fails or overflows
		integer = 0; // Reset _int to avoid using an invalid value
	}
	errno = 0; // Reset errno after conversion
	return (static_cast<int>(integer));
}

/* Checks if: 
1. No more than one dot in the string
2. No more than one alpha character (f or F) in the string AFTER the dot
Returns true if the string is formatted correctly, false otherwise.
 */
bool	ScalarConverter::isFormatted(const std::string &str)
{
	int dotCount = 0;
	int	alphaCount = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
			dotCount++;
		else if (str[i] == 'f' || str[i] == 'F')
			alphaCount++;
		if (dotCount < alphaCount)
			return (false); // If there's a 'f' before a '.', it's invalid
	}
	if (dotCount > 1 || alphaCount > 1)
		return (false);
	return (true);
}

	/* * */

// Checks if the string isn't empty, contains only valid characters, and has no more than one .
// Returns true if the string is valid, false otherwise.
bool	ScalarConverter::isValidString(const std::string &str)
{
	const std::string allowed = STR_ALLOWED;

	if (_isSpecial)
		return (true); // If it's a special value, we don't need to validate the string further
	if (str.empty() || !isStrPrintable(str))
		return (false);
	if (str.length() == 1 && isSingleCharAndNotNum(str)) // If it's a single character, it's valid
		return (true);
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (allowed.find(str[i]) == std::string::npos) //white list of characters
			return false;
	}
	if (!isFormatted(str))
		return (false);
	return (true);
}

// Check if the string is a special value like "inf", "-inf", "nan", etc.
// Returns true if the string is a special value, false otherwise.
void ScalarConverter::isSpecial(const std::string &str)
{
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf"
		|| str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
	{
		_isSpecial = true;
		_overflowedInt = true; // Set overflowedInt to true for special values
	}
	else
		_isSpecial = false;
}

// Check if the string is printable
// Returns true if all characters are printable
// Returns false if any character is not printable
bool	ScalarConverter::isStrPrintable(const std::string &str)
{
	int cursor = 0;

	while (str[cursor])
	{
		if (!std::iswprint(str[cursor]) && !std::iswspace(str[cursor]))
			return (false);
		cursor++;	
	}
	return (true);
}

// Check if the string is a single character AND not a digit
bool ScalarConverter::isSingleCharAndNotNum(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

/* ************************************************************************** */

void	ScalarConverter::parser(const std::string &value)
{
	isSpecial(value); // Check if the string is a special value and set _isSpecial accordingly
	if (!isValidString(value))
		throw ScalarConverterUndefined("Invalid input string: " + value);
	if (isSingleCharAndNotNum(value))
	{
		_int = static_cast<int>(value[0]);		// Non-implecit conversion from char to int. Can be implecit.
		_double = static_cast<double>(_int);
		return ;
	}
	if (!_isSpecial)		// if the string is NOT a special value
		_int = ft_strtoi(value);
	_double = strtod(value.c_str(), NULL); // Convert to double
}

	/* * */

void	ScalarConverter::display()
{
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}

void	ScalarConverter::displayChar()
{
	if (_overflowedInt)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (iswprint(_int))
		std::cout << "char: '" << static_cast<char>(_int) << "'" << std::endl;
	else if (_int >= 0 && _int <= 127)
		std::cout << "char: Non printable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	ScalarConverter::displayInt()
{
	if (_overflowedInt)
	{
		if (_isSpecial)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
	}
	else
		std::cout << "int: " << _int << std::endl;
}

void	ScalarConverter::displayFloat()
{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_double) << "f" << std::endl;
}

void	ScalarConverter::displayDouble()
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

void	ScalarConverter::convert(const std::string &value)
{
	parser(value);
	display();
	_overflowedInt = false; // Reset the overflow flag for the next conversion
	_isSpecial = false; // Reset the special flag for the next conversion
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

const char* ScalarConverterException::what() const throw()
{
	return _message.c_str();
}

// ScalarConverterException::ScalarConverterException()
// {

// };

ScalarConverterException::~ScalarConverterException() throw () {};                                		// Destructor

ScalarConverterUndefined::ScalarConverterUndefined(const std::string &message) 
{
	_message = message; // 
};
