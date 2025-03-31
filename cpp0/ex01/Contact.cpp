/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:20:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/03/29 04:22:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Methods, setters and getters
#include "Contact.hpp"

// Constructor
Contact::Contact()
{
	this->_first = "";
	this->_last = "";
	this->_nick = "";
	this->_secret = "";
	this->_phone = -1;
};

/* ************************************************************************** */
// PRIVATE METHODS

void Contact::setFirst(std::string f)
{
	this->_first = f;
};

void Contact::setLast(std::string l)
{
	this->_last = l;
};

void Contact::setNick(std::string n)
{
	this->_nick = n;
};

void Contact::setSecret(std::string s)
{
	this->_secret = s;
};

void Contact::setPhone(_phone_number p)
{
	this->_phone = p;
};

std::string Contact::cut(std::string str){
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return (str);
}

/* ************************************************************************** */
// PUBLIC METHODS

void Contact::Display()
{
	std::cout << "First name: " << _first << std::endl;
	std::cout << "Last name: " << _last << std::endl;
	std::cout << "Nickname: " << _nick << std::endl;
	std::cout << "Phone number: " << _phone << std::endl;
	std::cout << "Darkest secret: " << _secret << std::endl;
	std::cout << std::endl;
};

void Contact::DisplaySearch(int index)
{
	std::cout 
		<< std::right << std::setw(10) << index << "|"
		<< std::right << std::setw(10) << this->cut(_first) << "|" 
		<< std::right << std::setw(10) << this->cut(_last) << "|" 
		<< std::right << std::setw(10) << this->cut(_nick) << std::endl;
};

void Contact::setContact(std::string f, std::string l, std::string n, _phone_number p, std::string s)
{
	setFirst(f);
	setLast(l);
	setNick(n);
	setPhone(p);
	setSecret(s);
}
