/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:46:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/03 16:23:40 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <cstring>
# include <iomanip>

# define _PHONE_NUMBER long int
# define _STRING_LIMIT 10
# define _STRING_LIMIT_POS (_STRING_LIMIT - 1)

class Contact
{
	private:
		std::string _first;
		std::string _last;
		std::string _nick;
		std::string _secret;
		_PHONE_NUMBER _phone; // Crappy software, I could use a string instead to store all the phone numbers or long phone numbers
						// like `Fix: +33 6 12 34 56 78 Mobile: +33 1 23 45 67 89`

		void setFirst(std::string f);
		void setLast(std::string l);
		void setNick(std::string n);
		void setSecret(std::string s);
		void setPhone(_PHONE_NUMBER p);
		std::string cut(std::string str);

	public:
		// Constructor
		Contact();
		// Destructor
		~Contact();
		// Setters
		void setContact(std::string f, std::string l, std::string n, _PHONE_NUMBER p, std::string s);
		// Getters
		void Display();
		void DisplaySearch(int index);
};

#endif