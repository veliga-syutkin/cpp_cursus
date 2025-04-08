/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/08 16:02:38 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl BigSmoke;
	std::cout << "\t--- Complain Level: DEBUG \t---" << std::endl;
	BigSmoke.complain("DEBUG");
	std::cout << "\t--- Complain Level: INFO \t---" << std::endl;
	BigSmoke.complain("INFO");
	std::cout << "\t--- Complain Level: WARNING \t---" << std::endl;
	BigSmoke.complain("WARNING");
	std::cout << "\t--- Complain Level: ERROR \t---" << std::endl;
	BigSmoke.complain("ERROR");
	std::cout << "\t--- Complain Level: UNDEFINED \t---" << std::endl;
	BigSmoke.complain("no");
	std::cout << "\t--- Complain Level: KILLED \t---" << std::endl;
	BigSmoke.complain("");
}
