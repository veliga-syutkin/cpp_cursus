/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:37:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/10 09:59:38 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include "../terminal_colors.hpp"
# include <iostream>
# include <stack>
# include <iterator>
# include <list>


// # define size_type unsigned int

/*
	I meaaaaaaaaaaan... 
	Since `stack` is `container adaptor`, it means:
	- it has in itself a container (like `deque` or `vector`)
	- it has no iterators, but it can use iterators of its container
	And so, we just have to access the container of `stack` and use its iterators.
	- `std::stack` is not a container, but an adaptor that uses a container
	- `std::stack` does not provide iterators, but we can access the underlying container's iterators. 
	Yes. That's it.
*/
template <typename T>
class MutantStack : public std::stack<T>
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		MutantStack();                                	// Default constructor
		MutantStack(const MutantStack &other);         	// Copy constructor
		MutantStack &operator=(const MutantStack &other); // Assignment operator
		~MutantStack();                                	// Destructor

		typedef typename std::stack<T>::container_type::iterator			   iterator;
		typedef typename std::stack<T>::container_type::const_iterator		   const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	   reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void);
		iterator end(void);

		const_iterator begin(void) const;
		const_iterator end(void)   const;

		reverse_iterator rbegin(void);
		reverse_iterator rend(void);

		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void)   const;
};

# include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
