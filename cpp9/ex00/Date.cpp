/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/08/20 12:43:36 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <sstream>

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Date::Date()
{
	// std::cout << TERMINAL_GREEN << "\tDefault constructor Date called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Date::Date(const Date &other)
{
	this->date = other.date;
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	// std::cout << TERMINAL_GREEN << "\tCopy constructor Date called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Date &Date::operator=(const Date &other)
{
	if (this != &other)
	{
		this->date = other.date;
		this->year = other.year;
		this->month = other.month;
		this->day = other.day;
		// std::cout << TERMINAL_GREEN << "\tAssignation operator Date called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Date::~Date()
{
	// std::cout << TERMINAL_GREEN << "\tDestructor Date called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

/**
 * @brief Creates a date as an unsigned int in the following format: YYYYMMDD
 */
void Date::setDate(unsigned short year, unsigned short month, unsigned short day)
{
	// Check the fking 29th feb
	if (month == 2 && day == 29)
	{
		if (year % 4 == 0)
		{
			if (year % 100 == 0 && year % 400 != 0)
				throw DateExceptionFebruaryOver29();
		}
		else
			throw DateExceptionFebruaryOver28();

	}

	if (month == 2 && day > 29)
		throw DateExceptionFebruaryOver28();

	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		throw DateExceptionMonthWith30();

	if (month == 0 || month > 12 || day == 0 || day > 31)
		throw DateExceptionDayOrMonthImpossible();

	this->year = year;
	this->month = month;
	this->day = day;

	date = static_cast<unsigned int>(year) * 10000 + static_cast<unsigned int>(month) * 100 + static_cast<unsigned int>(day);
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

/**
 * @brief Constructs a Date object with the specified year, month, and day.
 */
Date::Date(unsigned short year, unsigned short month, unsigned short day)
{
	setDate(year, month, day);
}

/**
 * @brief Constructs a Date object with the specified year, month, and day.
 */
Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	setDate(static_cast<unsigned short>(year), static_cast<unsigned short>(month), static_cast<unsigned short>(day));
}

/**
 * @brief Constructs a Date object with the specified year, month, and day.
 */
Date::Date(int year, int month, int day)
{
	setDate(static_cast<unsigned short>(year), static_cast<unsigned short>(month), static_cast<unsigned short>(day));
}

/**
 * @brief Returns the date as an int.
 * @return The date in YYYYMMDD format, as an int.
 */
unsigned int Date::getDate() const
{
	return date;
}

/**
 * @brief Returns the year.
 * @return The year as an unsigned int.
 */
unsigned int Date::getYear() const
{
	return static_cast<unsigned int>(year);
}

/**
 * @brief Returns the month.
 * @return The month as an unsigned int.
 */
unsigned int Date::getMonth() const
{
	return static_cast<unsigned int>(month);
}

/**
 * @brief Returns the day.
 * @return The day as an unsigned int.
 */
unsigned int Date::getDay() const
{
	return static_cast<unsigned int>(day);
}

/**
 * @brief Less than operator for comparing two Date objects.
 * @param other The other Date object to compare against.
 * @return True if this date is earlier than the other date, false otherwise.
 */
bool	Date::operator<(const Date &other) const
{
	return this->date < other.date;
}

/**
 * @brief Not equal operator for comparing two Date objects.
 * @param other The other Date object to compare against.
 * @return True if this date is not equal to the other date, false otherwise.
 */
bool	Date::operator!=(const Date &other) const
{
	return this->date != other.date;
}

/**
 * @brief Overload the output stream operator for the Date class.
 * @param os The output stream.
 * @param date The Date object to output.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream &os, const Date &date)
{
	std::stringstream ss_year;
	ss_year << date.getYear();
	std::stringstream ss_month;
	ss_month << date.getMonth();
	std::stringstream ss_day;
	ss_day << date.getDay();

	// Pad with leading zeros if necessary
	while (ss_year.str().length() < 4) ss_year.str("0" + ss_year.str());
	while (ss_month.str().length() < 2) ss_month.str("0" + ss_month.str());
	while (ss_day.str().length() < 2) ss_day.str("0" + ss_day.str());

	os << ss_year.str() << "-" << ss_month.str() << "-" << ss_day.str();
	return os;
}

DateException::DateException(const std::string &msg) : _msg(msg) {};

DateException::~DateException() throw() {};

const char *DateException::what() const throw()
{
	return _msg.c_str();
}

DateExceptionDayOrMonthImpossible::DateExceptionDayOrMonthImpossible() : DateException("DateExceptionDayOrMonthImpossible: Day or month is invalid"){};

DateExceptionMonthWith30::DateExceptionMonthWith30() : DateException("DateExceptionMonthWith30: Month has 30 days not 31"){};

DateExceptionFebruaryOver28::DateExceptionFebruaryOver28() : DateException("DateExceptionFebruaryOver28: February is 28 days long that year"){};

DateExceptionFebruaryOver29::DateExceptionFebruaryOver29() : DateException("DateExceptionFebruaryOver29: Exceptionally that year's February has 29 days only"){};
