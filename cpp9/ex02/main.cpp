/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:57:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/19 18:33:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <vector>
#include <deque>

#include "../terminal_colors.hpp"

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

int main(int argc, char **argv)
{
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;

    if (argc == 1)
        return (0);
    for (int i = 1; i < argc; i++)
    {
        unsigned int value;
        if (safeStrToUInt(argv[i], value))
        {
            std::cout << TERMINAL_GREEN << "[DEBUG] Success: " << argv[i] << " is a valid unsigned int." << TERMINAL_RESET << std::endl;
            vec.push_back(value);
            deq.push_back(value);
        }
        else
        {
            std::cerr << TERMINAL_RED << "Error: " << argv[i] << " is not a valid unsigned int." << TERMINAL_RESET << std::endl;
            return (1);
        }
    }
    return (0);
}