/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:05:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 17:05:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
		para2trap.guardGate(); // This should not cause an error, but will not do anything since the ScavTrap is dead
	}
	{
		FragTrap fragtrap("FRGT");
		fragtrap.highFivesGuys();
		fragtrap.attack("target1");
		fragtrap.takeDamage(3);
		fragtrap.beRepaired(2);
		fragtrap.takeDamage(10);
		fragtrap.attack("target2");
		fragtrap.beRepaired(5);
		fragtrap.highFivesGuys();

		FragTrap para3trap("Para3Trap");
		para3trap.beRepaired(-1);
		para3trap.takeDamage(11);
		para3trap.takeDamage(-1);
		para3trap.highFivesGuys(); // This should not cause an error, but will not do anything since the FragTrap is dead
	}
	return (0);
}