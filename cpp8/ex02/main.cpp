/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:49:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/17 08:49:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib> 

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		//[...]

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);		// demonstration that MutantStack is `stack` container compatible
	}
	std::cout << TERMINAL_CYAN << "Using std::list as a container:" << TERMINAL_RESET << std::endl;
	{
		#define MutantStack std::list
		#define push push_back
		#define top back				// keep LIFO logic
		#define pop pop_back			// keep LIFO logic
		
		MutantStack<int> mstack;
		std::list<int> lst;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		//[...]

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		// std::stack<int> s(mstack);
	}
	std::cout << TERMINAL_CYAN << "Test inspired from the internet:" << TERMINAL_RESET << std::endl;
	{
		MutantStack<int> stack;

		//rng init
		srand(time(NULL));

		for (int cursor = 0; cursor < (rand() % 100) * 10; ++cursor) {
			stack.push(rand() % 10000);
		}

		for (MutantStack<int>::iterator cursor = stack.begin(); cursor != stack.end(); cursor++) {
			std::cout << *cursor;
			if (cursor != stack.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
