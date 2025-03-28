/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:46:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/28 21:28:14 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <cstring>
# include <iomanip>

class Contact
{
	private:
		std::string _first;
		std::string _last;
		std::string _nick;
		std::string _secret;
		uint32_t _phone; // Crappy software, I could use a string instead to store all the phone numbers or long phone numbers
						// like `Fix: +33 6 12 34 56 78 Mobile: +33 1 23 45 67 89`

	// Private method to set a char array with a limit
		// void setChar(std::string dest, const char *str);

	public:
		// Constructor
		Contact() {}
		// Destructor
		~Contact() {}
		// Setters
		void setFirst(std::string f);
		void setLast(std::string l);
		void setNick(std::string n);
		void setSecret(std::string s);
		void setPhone(uint32_t p);
		// Getters
		void Display();
		void DisplaySearch();
};

#endif