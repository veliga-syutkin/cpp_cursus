/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:12:13 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/07 02:15:53 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Human.hpp"

class HumanA : public Human
{
	private: 
	// Weapon &_weapon;
	public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
};

#endif