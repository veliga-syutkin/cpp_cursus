/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:57:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/23 14:51:10 by vsyutkin         ###   ########.fr       */
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

/**
 * @brief Sorts a vector of unsigned integers using a variation of the Ford-Johnson (Merge-Insertion) algorithm.
 *
 * This function sorts the input vector in ascending order. It works by:
 * 1. Pairing adjacent elements and swapping them if necessary so that the larger element is second.
 * 2. Inserting the second element of each pair into a new sorted container using binary insertion.
 * 3. Merging the remaining elements (the first of each pair and any leftover) into the sorted container.
 * 4. Assigning the sorted container back to the input vector.
 *
 * @param vec Reference to a std::vector<unsigned int> to be sorted in-place.
 */
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

/**
 * @brief Safely converts a C-string to an unsigned int.
 *
 * Attempts to parse the given C-string as an unsigned integer. If the string
 * represents a valid unsigned integer within the range of unsigned int, the
 * result is stored in the provided reference and the function returns true.
 * Otherwise, the function returns false and the result is not modified.
 *
 * @param str     The C-string to convert.
 * @param result  Reference to an unsigned int where the result will be stored on success.
 * @return true if the conversion was successful and within range, false otherwise.
 */
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

/**
 * @brief Sorts a std::deque<unsigned int> using a variation of the Ford-Johnson (Merge-Insertion) algorithm.
 *
 * This function sorts the input deque in ascending order. The algorithm works by:
 * 1. Pairing adjacent elements and swapping them if necessary so that the larger element is second.
 * 2. Inserting the second element of each pair into a new sorted container, maintaining sorted order.
 * 3. Merging the remaining (first) elements of each pair into the sorted container.
 * 
 * The result is that the input deque is sorted in-place.
 *
 * @param deq Reference to the std::deque<unsigned int> to be sorted.
 */
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

/**
 * @brief Entry point of the program. Parses command-line arguments, validates them as unsigned integers,
 *        and stores them in both a std::vector and a std::deque. Then, it prints the input sequence,
 *        sorts both containers using the Ford-Johnson algorithm (implemented in forJhonsonVec and forJhonsonDeque),
 *        and measures the time taken for each sort. Finally, it prints the sorted sequence and timing results.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Returns 0 on success, or 1 if an invalid input is encountered.
 *
 * @note
 * - Uses safeStrToUInt to safely convert input strings to unsigned integers.
 * - Uses TERMINAL_* macros for colored terminal output.
 * - Sorting is performed by forJhonsonVec (for std::vector) and forJhonsonDeque (for std::deque).
 * - Timing is measured using std::clock().
 */
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