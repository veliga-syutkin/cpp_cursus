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
# include <iostream>
# include <climits>
# include <ostream>

# define STR_ALLOWED "0123456789.-+fFdD"

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter(void);

		bool	isFAtEnd(const std::string &str);
		bool	isDotBetweenDigits(const std::string &str);
		// bool	isValidChar(const std::string &str);
		bool	isValidString(const std::string &str);
		bool	isSpecial(const std::string &str);
		int		dotCounter(const std::string &str);

		// static type	getType(const std::string &value);
		static void display(const char character, const int integer, const float singleFloat, const double doubleFloat);
	
	protected:

	public:
		static void convert(const std::string &value);
};

class	ScalarConverterException : public std::exception
{
	private:
	
	protected:
		std::string _message;
	
	public:
		~ScalarConverterException() throw ();                                		// Destructor
		const char* what() const throw();
};

class	ScalarConverterOverflow : public ScalarConverterException
{
	public:
		ScalarConverterOverflow(const std::string &message);
};

class	ScalarConverterUndefined : public ScalarConverterException
{
	public:
		ScalarConverterUndefined(const std::string &message);
};

#endif // SCALARCONVERTER_HPP
