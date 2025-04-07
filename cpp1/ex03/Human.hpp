/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:43:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/07 02:11:31 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Weapon.hpp"


class Human
{
	protected:
	std::string _name;
	Weapon *_weapon;
	Human(const std::string name, Weapon &weapon);
	Human(const std::string name);

	public:
	Human();
	~Human();
	const std::string &getName() const;
	void setName(std::string type);
	void attack();
	void setWeapon(Weapon *weapon);
};

#endif