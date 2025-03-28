/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:46:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/28 19:00:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <cstring>

# define CONTACT_LENGTH 11

class Contact
{
	private:
		char _first[CONTACT_LENGTH];
		char _last[CONTACT_LENGTH];
		char _nick[CONTACT_LENGTH];
		char _secret[CONTACT_LENGTH];
		uint32_t _phone;

	// Private method to set a char array with a limit
		void setChar(char *dest, const char *str);

	public:
		// Constructor
		Contact() {}
		// Destructor
		~Contact() {}
		// Setters
		void setFirst(const char *first);
		void setLast(const char *last);
		void setNick(const char *nick);
		void setSecret(const char *secret);
		void setPhone(const char *phone);
		// Getters
		void Display();
		void DisplaySearch();
};

#endif