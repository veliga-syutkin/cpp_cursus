/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:05:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 18:17:18 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
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
	std::cout << std::endl;
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
	std::cout << std::endl;
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
	std::cout << std::endl;
	{
		DiamondTrap diamondtrap("DMDT");
		diamondtrap.whoAmI();
		diamondtrap.attack("target1");
		diamondtrap.takeDamage(3);
		diamondtrap.beRepaired(2);
		diamondtrap.takeDamage(10);
		diamondtrap.attack("target2");
		diamondtrap.beRepaired(5);
		diamondtrap.whoAmI();
		diamondtrap.highFivesGuys();
		diamondtrap.guardGate();

		DiamondTrap para4trap("Para4Trap");
		para4trap.beRepaired(-1);
		para4trap.takeDamage(11);
		para4trap.takeDamage(-1);
		para4trap.whoAmI(); // This should not cause an error, but will not do anything since the DiamondTrap is dead
	}
	return (0);
}