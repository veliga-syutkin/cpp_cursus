/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:51:33 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/08 15:12:35 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ostream>

// Fuking C++98 restriction, so we can't use `std::array` or `std::vector` with a fixed size.
template <typename Container>
void fillContainer(Container &container, int values[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
        container.push_back(values[i]);
}

int main() 
{
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec;
        fillContainer(vec, arr, 5);

        int arr2[] = {10, 20, 30, 40, 50};
        std::list<int> lst;
        fillContainer(lst, arr2, 5);

        try
        {
            std::cout << "Finding 3 in vector: " << *easyfind(vec, 3) << std::endl;
            std::cout << "Finding 6 in vector: " << *easyfind(vec, 6) << std::endl; // This will throw an exception
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            std::cout << "Finding 20 in list: " << *easyfind(lst, 20) << std::endl;
            std::cout << "Finding 60 in list: " << *easyfind(lst, 60) << std::endl; // This will throw an exception
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        int arr[] = {100, 200, 300, 400, 500};
        std::deque<int> deq;
        fillContainer(deq, arr, 5);

        try
        {
            std::cout << "Finding 300 in deque: " << *easyfind(deq, 300) << std::endl;
            std::cout << "Finding 700 in deque: " << *easyfind(deq, 700) << std::endl; // This will throw an exception
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}