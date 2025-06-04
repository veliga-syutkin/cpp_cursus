/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/06/03 12:21:05 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
double ScalarConverter::_double = 0.0;
bool ScalarConverter::_overflowedInt = false;

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

// Check if the string ends with 'f' or 'F'
bool	ScalarConverter::isFAtEnd(const std::string &str)
{
	// if (str.back() == 'f' || str.back() == 'F')
    if (!str.empty() && (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F'))
		return (true);
	return (false);
}

bool	ScalarConverter::isDotBetweenDigits(const std::string &str)
{
	// Check if the string contains a dot between digits
	size_t dotPos = str.find('.');
	if (dotPos != std::string::npos)
		return (true);
	return (false);
}

int	ScalarConverter::dotCounter(const std::string &str)
{
	// Count the number of dots in the string
	int count = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		count++;
	}
	return (count);
}

	/* * */

// Checks if the string isn't empty, contains only valid characters, and has no more than one dot.
// Returns true if the string is valid, false otherwise.
bool	ScalarConverter::isValidString(const std::string &str)
{
	const std::string allowed = STR_ALLOWED;

	if (str.empty())
		return (false);
	
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (allowed.find(str[i]) == std::string::npos) //white list of characters
			return false;
	}
	if (dotCounter(str) > 1)
		return (false);
	return (true);
}

// Check if the string is a special value like "inf", "-inf", "nan", etc.
// Returns true if the string is a special value, false otherwise.
// -----
// Returns 1 for "-inf(f)", 2 for "nan(f)", 3 for "+inf(f)", and 0 for other cases.
bool ScalarConverter::isSpecial(const std::string &str)
{
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
		return (true);
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
		return (true);
	return (false);
}

// Check if the string is printable
// Returns true if all characters are printable
// Returns false if any character is not printable
bool	ScalarConverter::isPrintable(const std::string &str)
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

bool ScalarConverter::isSingleChar(const std::string &str)
{
	if (str.length() == 1 && isPrintable(str) && !isdigit(str[0]))
		return (true);
	return (false);
}

	/* * */

// Output in the terminal
void	ScalarConverter::toDisplay(const std::string &character, const std::string &integer, const std::string &singleFloat, const std::string &doubleFloat)
{
	std::cout << "char: " << character << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << singleFloat << std::endl;
	std::cout << "double: " << doubleFloat << std::endl;
}

void	ScalarConverter::display()
{
	if (_overflowedInt)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
	}
	else
	{
		if (iswprint(_int) && _int >= 0 && _int <= 127)
			std::cout << "char: '" << static_cast<char>(_int) << "'" << std::endl;
		else
			std::cout << "char: Non printable" << std::endl;
		std::cout << "int: " << _int << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_double) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;
}

// void	ScalarConverter::display(const char character)
// {
	
// }

void	ScalarConverter::parser(const std::string &value)
{

	if (isSingleChar(value))
	{
		_int = static_cast<int>(value[0]);
		_double = static_cast<double>(_int);
		return ;
	}
	bool	special = isSpecial(value);
	if (!isValidString(value) && !special)
		throw ScalarConverterUndefined("Invalid input string: " + value);
	if (special)		// if the string is a special value
		_overflowedInt = true;	// true = 1
	else
		_int = static_cast<int>(strtol(value.c_str(), NULL, 10));
	_double = strtod(value.c_str(), NULL); // Convert to double
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

void	ScalarConverter::convert(const std::string &value)
{
	parser(value);
	display();
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
