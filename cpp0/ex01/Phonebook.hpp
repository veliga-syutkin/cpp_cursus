/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:46:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/31 18:21:56 by vsyutkin         ###   ########.fr       */
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
		bool inputCheckerInt(std::string display, _phone_number &cell);
		void inputCheckerString(std::string display, std::string &str);
	public:
		// Constructor
		Phonebook();
		// Destructor
		~Phonebook(){};
		// Setters
		void addContact();
		void searchContact();
};

#endif