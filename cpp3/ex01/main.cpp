/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:05:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 17:02:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
int main()
{
	{	ClapTrap claptrap("CLTP");

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
	}
	{
		ScavTrap scavtrap("SCVT");

		scavtrap.attack("target1");
		scavtrap.takeDamage(3);
		scavtrap.beRepaired(2);
		scavtrap.takeDamage(10);
		scavtrap.attack("target2");
		scavtrap.beRepaired(5);
		scavtrap.guardGate();

		ScavTrap para2trap("Para2Trap");
		para2trap.beRepaired(-1);
		para2trap.takeDamage(11);
		para2trap.takeDamage(-1);
	}
	return (0);
}