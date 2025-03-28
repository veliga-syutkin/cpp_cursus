/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:46:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/28 22:02:38 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

// template <typename T> not sure if it's legal

class Phonebook
{
	private:
		Contact _contacts[8];
		int _index;
		void pushIndex();
		void inputCheckerString(std::string cell, std::string temp);
		void inputCheckerInt(std::string cell, uint32_t temp);
	public:
		// Constructor
		Phonebook(){};
		// Destructor
		~Phonebook(){};
		// Setters
		void addContact();
		void searchContact();
		void exit();
		void displayAllContacts();
		void displayContact(int index);
};

#endif