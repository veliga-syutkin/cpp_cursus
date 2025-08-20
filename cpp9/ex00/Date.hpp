/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/08/20 12:43:36 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

# include "../terminal_colors.hpp"
# include <iostream>

class Date
{
	private:										// Private members
		unsigned int	date;
		unsigned short	year;
		unsigned short	month;
		unsigned short	day;

		void setDate(unsigned short year, unsigned short month, unsigned short day);
		Date();                                	// Default constructor

	protected:										// Protected members for inheritance

	public:
		Date(const Date &other);         	// Copy constructor
		Date(unsigned short year, unsigned short month, unsigned short day);
		Date(unsigned int year, unsigned int month, unsigned int day);
		Date(int year, int month, int day);

		Date &operator=(const Date &other); // Assignment operator
		~Date();                                	// Destructor

		unsigned int getDate() const;
		unsigned int getYear() const;
		unsigned int getMonth() const;
		unsigned int getDay() const;

		bool operator<(const Date &other) const;	// Less than operator
		bool operator!=(const Date &other) const;	// Not equal operator
};

class DateException : public std::exception
{
	protected:
		std::string _msg;

	public:
		~DateException() throw ();
		DateException(const std::string &msg);
		const char* what() const throw();
};

class DateExceptionDayOrMonthImpossible : public DateException
{
	public:
		DateExceptionDayOrMonthImpossible();
};

class DateExceptionMonthWith30 : public DateException
{
	public:
		DateExceptionMonthWith30();
};

class DateExceptionFebruaryOver28 : public DateException
{
	public:
		DateExceptionFebruaryOver28();
};

class DateExceptionFebruaryOver29 : public DateException
{
	public:
		DateExceptionFebruaryOver29();
};

std::ostream& operator<<(std::ostream &os, const Date &date);

#endif // DATE_HPP
