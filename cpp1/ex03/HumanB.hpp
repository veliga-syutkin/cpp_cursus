/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:43:50 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/07 02:30:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Human.hpp"

class HumanB : public Human
{
	private: 

	public:
	HumanB(std::string name, Weapon &weapon);
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
};

#endif