/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/06/03 12:21:05 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include "../terminal_colors.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <climits>
# include <ostream>
# include <cmath>
# include <exception>

# define STR_ALLOWED "0123456789.-+fF"

class ScalarConverter {
	private:
		// static char		_char;		// deprecated because _int can be used instead
		static long		_int;
		// static float	_float;		// deprecated because _double can be used instead
		static double	_double;

		static bool		_overflowedInt;

		ScalarConverter(void);
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter(void);

		static bool	isFAtEnd(const std::string &str);
		static bool	isDotBetweenDigits(const std::string &str);
		// bool	isValidChar(const std::string &str);
		static bool	isValidString(const std::string &str);
		static bool	isSpecial(const std::string &str);
		static int	dotCounter(const std::string &str);
		static bool	isSingleChar(const std::string &str);
		static bool isPrintable(const std::string &str);
		static void	parser(const std::string &value);

		static void toDisplay(const std::string &character, const std::string &integer, const std::string &singleFloat, const std::string &doubleFloat);
		// static type	getType(const std::string &value);
		static void display();
	
	protected:

	public:
		static void convert(const std::string &value);
};

// Generic exception for ScalarConverter
class	ScalarConverterException : public std::exception
{
	private:
	
	protected:
		std::string _message;
	
	public:
		~ScalarConverterException() throw ();                                		// Destructor
		const char* what() const throw();
};

// String is overflowing after conversion
// class	ScalarConverterOverflow : public ScalarConverterException
// {
// 	public:
// 		ScalarConverterOverflow(const std::string &message);
// };
// 
// // Exception when the string cannot be converted (like, "Hello World!")
// class	ScalarConverterStringException : public ScalarConverterException
// {
// 	public:
// 		ScalarConverterStringException(const std::string &message);
// };

// Exception for the undefined string errors
class	ScalarConverterUndefined : public ScalarConverterException
{
	public:
		ScalarConverterUndefined(const std::string &message);
};

#endif
