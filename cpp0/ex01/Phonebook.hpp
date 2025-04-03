/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:46:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/03 16:23:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

// template <typename T> not sure if it's legal

class Phonebook
{
	private:
		Contact _contacts[8];
		int _index;
		void pushIndex();
		bool inputCheckerInt(std::string display, _PHONE_NUMBER &cell);
		void inputCheckerString(std::string display, std::string &str);
		bool isprintable(std::string str);
	public:
		// Constructor
		Phonebook();
		// Destructor
		~Phonebook();

		void addContact();
		void searchContact();
};

#endif