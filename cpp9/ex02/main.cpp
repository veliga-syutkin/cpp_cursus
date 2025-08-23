/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:57:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/23 13:37:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

#include "../terminal_colors.hpp"

void	fordJhonsonVec(std::vector<unsigned int> &vec)
{
	std::vector<unsigned int>::iterator cursor;
	std::vector<unsigned int>::iterator	current;
	std::vector<unsigned int>::iterator	previous;
	std::vector<unsigned int> sorted;

	if (vec.size() < 2)					// don't sort if there is no elements to sort
		return ;

	sorted.reserve(vec.size());			// reserve space for sorted vector and avoid reallocations
	cursor = vec.begin();
	while (cursor != vec.end())
	{
		previous = cursor;				// store the 1st member of the pair
		cursor++;
		if (cursor == vec.end())		// we are at the end of the vector
			break ;
		current = cursor;				// store the 2nd member of the pair
		if (*current < *previous)		// if the current value is less than the previous one, we swap them
			std::swap(*current, *previous);
		cursor++;						// go to next pair
	}

	/*
	Put 2nd members of pairs into sorted container sorting them at insertion
	*/
	cursor = vec.begin();
	while (cursor != vec.end())
	{
		cursor++;
		if (cursor == vec.end())		// we are at the end of the vector
			break ;
		previous = std::lower_bound(sorted.begin(), sorted.end(), *cursor);
		sorted.insert(previous, *cursor);	// insert 2nd member of the pair into sorted container
		cursor++;
	}

	/*
	Merge the leftovers into sorted
	*/
	cursor = vec.begin();
	while (cursor != vec.end())
	{
		previous = std::lower_bound(sorted.begin(), sorted.end(), *cursor);
		sorted.insert(previous, *cursor);
		cursor++;
		if (cursor == vec.end())		// we are at the end of the vector
			break ;
		else
			cursor++;
	}

	vec = sorted;
}

bool safeStrToUInt(const char *str, unsigned int &result)
{
    char *endptr = NULL;
    unsigned long val = std::strtoul(str, &endptr, 10);

    if (*endptr != '\0') // Not a valid number
        return false;
    if (val > UINT_MAX) // Overflow
        return false;
    result = static_cast<unsigned int>(val);
    return true;
}

void	fordJhonsonDeque(std::deque<unsigned int> &deq)
{
	std::deque<unsigned int>::iterator cursor;
	std::deque<unsigned int>::iterator	current;
	std::deque<unsigned int>::iterator	previous;
	std::deque<unsigned int> sorted;

	if (deq.size() < 2)					// don't sort if there is no elements to sort
		return ;

	cursor = deq.begin();
	while (cursor != deq.end())
	{
		previous = cursor;				// store the 1st member of the pair
		cursor++;
		if (cursor == deq.end())		// we are at the end of the deque
			break ;
		current = cursor;				// store the 2nd member of the pair
		if (*current < *previous)		// if the current value is less than the previous one, we swap them
			std::swap(*current, *previous);
		cursor++;						// go to next pair
	}

	/*
	Put 2nd members of pairs into sorted container sorting them at insertion
	*/
	cursor = deq.begin();
	while (cursor != deq.end())
	{
		cursor++;
		if (cursor == deq.end())		// we are at the end of the deque
			break ;
		previous = std::lower_bound(sorted.begin(), sorted.end(), *cursor);
		sorted.insert(previous, *cursor);	// insert 2nd member of the pair into sorted container
		cursor++;
	}

	/*
	Merge the leftovers into sorted
	*/
	cursor = deq.begin();
	while (cursor != deq.end())
	{
		previous = std::lower_bound(sorted.begin(), sorted.end(), *cursor);
		sorted.insert(previous, *cursor);
		cursor++;
		if (cursor == deq.end())		// we are at the end of the deque
			break ;
		else
			cursor++;
	}

	deq = sorted;
}

int main(int argc, char **argv)
{
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;
	clock_t start_time_vec, end_time_vec;
	clock_t start_time_deq, end_time_deq;

    if (argc == 1)
        return (0);
    for (int i = 1; i < argc; i++)
    {
        unsigned int value;
        if (safeStrToUInt(argv[i], value))
        {
            vec.push_back(value);
            deq.push_back(value);
        }
        else
        {
            std::cerr << TERMINAL_RED << "Error: " << argv[i] << " is not a valid unsigned int." << TERMINAL_RESET << std::endl;
            return (1);
        }
	}

	std::cout << TERMINAL_GREEN << "" << "Before: ";
	for (size_t j = 0; j < vec.size(); j++)
		std::cout << vec[j] << " ";
	std::cout << TERMINAL_RESET << std::endl;
	
	start_time_vec = std::clock();
	fordJhonsonVec(vec);
	end_time_vec = std::clock();

	start_time_deq = std::clock();
	fordJhonsonDeque(deq);
	end_time_deq = std::clock();

	std::cout << TERMINAL_YELLOW << "After: ";
	for (size_t j = 0; j < vec.size(); j++)
		std::cout << vec[j] << " ";
	std::cout << TERMINAL_RESET << std::endl;

	std::cout << TERMINAL_YELLOW << "Time taken for " << argc-1 << " elements with vector: " << 1000.0 * (end_time_vec - start_time_vec) / CLOCKS_PER_SEC << " ms" << TERMINAL_RESET << std::endl;
	std::cout << TERMINAL_YELLOW << "Time taken for " << argc-1 << " elements with deque: " << 1000.0 * (end_time_deq - start_time_deq) / CLOCKS_PER_SEC << " ms" << TERMINAL_RESET << std::endl;

    return (0);
}