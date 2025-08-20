/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:58:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/20 16:36:12 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <map>
#include <climits>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <cfloat> // pour FLT_MAX

#include "Date.hpp"

/* 
Database can't have duplicate dates. 
BUT the input CAN have duplicates.
*/

/**
 * @brief Open and setup database (default: data.csv)
 * @param database The input file stream for the database.
 * @return A map containing the date and its associated float value.
 */
std::map<Date, float> databaseSetup(std::ifstream &database)
{
	std::map<Date, float> data;
	std::string line;
	unsigned short	year;
	unsigned short	month;
	unsigned short	day;

	std::getline(database, line);
	if (!(line == "date,exchange_rate"))
		throw std::runtime_error("Invalid database format");
	while (std::getline(database, line))
	{
		if (line[4] != '-' && line[7] != '-')
		{
			std::cerr << "Error reading line - no date detected: " << line << std::endl;
			continue;
		}
		size_t comma = line.find(',');
		if (comma == std::string::npos)
		{
			std::cerr << "Error reading line - corrupted line: " << line << std::endl;
			continue;
		}
		std::string dateStr = line.substr(0, comma);
		std::string valueStr = line.substr(comma + 1);
		char *endptr;
		errno = 0;
		double dval = std::strtod(valueStr.c_str(), &endptr);

		if (errno == ERANGE || dval > FLT_MAX || dval < -FLT_MAX)
		{
			std::cerr << "Overflow or underflow in value: " << valueStr << std::endl;
			continue;
		}
		if (*endptr != '\0')
		{
			std::cerr << "Invalid float value: " << valueStr << std::endl;
			continue;
		}
		float value = static_cast<float>(dval);

	std::stringstream ssYear(dateStr.substr(0, 4));
	ssYear >> year;
	std::stringstream ssMonth(dateStr.substr(5, 2));
	ssMonth >> month;
	std::stringstream ssDay(dateStr.substr(8, 2));
	ssDay >> day;

		try
		{
			Date date(year, month, day);
			data[date] = value;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue ;
		}
	}

	return data;
}

/**
 * @brief Open and setup values from given file.
 * @param input The input file stream for the values.
 * @return A map containing the date and its associated float value.
 */
std::multimap<Date, float> inputSetup(std::ifstream &input)
{
	std::multimap<Date, float> data;
	std::string line;
	unsigned short	year;
	unsigned short	month;
	unsigned short	day;

	std::getline(input, line);
	if (!(line == "date | value"))
		throw std::runtime_error("Invalid input database format");
	while (std::getline(input, line))
	{
		if (line[4] != '-' && line[7] != '-')
		{
			std::cerr << "Error reading line - no date detected: " << line << std::endl;
			continue;
		}
		size_t pipe = line.find('|');
		if (pipe == std::string::npos || line[pipe - 1] != ' ' || line[pipe + 1] != ' ' || pipe + 2 >= line.size())
		{
			std::cerr << "Error reading line - corrupted line: " << line << std::endl;
			continue;
		}
		std::string dateStr = line.substr(0, pipe);
		std::string valueStr = line.substr(pipe + 2);
		char *endptr;
		errno = 0;
		double dval = std::strtod(valueStr.c_str(), &endptr);

		if (errno == ERANGE || dval > 1000 || dval < 0)
		{
			std::cerr << "Subject overflow or underflow in value: " << valueStr << std::endl;
			continue;
		}
		if (*endptr != '\0')
		{
			std::cerr << "Invalid float value: " << valueStr << std::endl;
			continue;
		}
		float value = static_cast<float>(dval);

		std::stringstream ssYear(dateStr.substr(0, 4));
		ssYear >> year;
		std::stringstream ssMonth(dateStr.substr(5, 2));
		ssMonth >> month;
		std::stringstream ssDay(dateStr.substr(8, 2));
		ssDay >> day;

		try
		{
			Date date(year, month, day);
			data.insert(std::make_pair(date, value));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue ;
		}
	}

	return data;
}

/**
 * @brief For each date in @param values calculates the multiplication at same (or previous) date in @param data
 * @param data The map containing the date and its associated float value from the database.
 * @param values The map containing the date and its associated float value from the input.
 * @return A map containing the merged data.
 */
std::multimap<Date, float> mergeData(const std::map<Date, float> &data, const std::multimap<Date, float> &values)
{
	std::multimap<Date, float> result;

	std::map<Date, float>::const_iterator nearest;

	// for (const auto &pair : values)			// not c++98 compatible
	for (std::multimap<Date, float>::const_iterator itValues = values.begin(); itValues != values.end(); ++itValues)
	{
		const Date &date = itValues->first;
		float value = itValues->second;

		nearest = data.lower_bound(itValues->first);
		if (nearest == data.end() || nearest->first != itValues->first)
		{
			if (nearest == data.begin())
			{
				std::cerr << "No previous date found for " << date << std::endl;
				continue ;
			}
			nearest--; // Get the previous date
		}
		// result[date] = value * nearest->second;
		result.insert(std::make_pair(date, value * nearest->second));
	}

	return result;
}

int main (int argc, char **argv)
{
	std::ifstream database;

	std::map<Date, float> data;
	std::multimap<Date, float> values;

	std::multimap<Date, float> result;

	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input> [database]" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input)
	{
		std::cerr << "Error opening file: " << argv[1] << std::endl;
		return 1;
	}

	if (argc == 3)
		database.open(argv[2]);
	else
		database.open("data.csv");
	if (!database)
	{
		std::cerr << "Error opening database: " << argv[2] << std::endl;
		return 1;
	}
	
	try
	{
		data = databaseSetup(database);
		values = inputSetup(input);
		result = mergeData(data, values);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		input.close();
		database.close();
		return 1;
	}

	for (std::multimap<Date, float>::const_iterator itResult = result.begin(); itResult != result.end(); ++itResult)
	{
		std::cout << itResult->first << " => " << itResult->second << " converted value." << std::endl;
	}

	database.close();
	input.close();

	return 0;
}