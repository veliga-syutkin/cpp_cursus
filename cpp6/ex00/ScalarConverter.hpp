/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:34:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 16:34:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "../terminal_colors.hpp"
# include <climits>
# include <cmath>
# include <cstdlib>
# include <cerrno>
# include <exception>
# include <iostream>
# include <iomanip>
# include <ostream>
# include <string>
# include <sstream>

# define STR_ALLOWED "0123456789.-+fF"

class ScalarConverter {
	private:
		// static char		_char;		// deprecated because _int can be used instead
		static long		_int;
		// static float	_float;		// deprecated because _double can be used instead
		static double	_double;

		static bool		_overflowedInt;
		static bool		_isSpecial;

		ScalarConverter(void);
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter(void);

		static bool	isFormatted(const std::string &str);
		static int	ft_strtoi(const std::string &value);
		static bool isStrPrintable(const std::string &str);
		static bool	isSingleCharAndNotNum(const std::string &str);
		static void	isSpecial(const std::string &str);
		static bool	isValidString(const std::string &str);

		static void displayChar();
		static void displayInt();
		static void displayFloat();
		static void displayDouble();

		static void	parser(const std::string &value);
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
