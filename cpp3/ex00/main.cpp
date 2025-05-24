/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:05:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 13:13:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main()
{
	ClapTrap claptrap("CLTP");

	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	claptrap.takeDamage(10);
	claptrap.attack("target2");
	claptrap.beRepaired(5);

	ClapTrap paratrap("ParaTrap");
	paratrap.beRepaired(-1);
	paratrap.takeDamage(11);
	paratrap.takeDamage(-1);

	return (0);
}