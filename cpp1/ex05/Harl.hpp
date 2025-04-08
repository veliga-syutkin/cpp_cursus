/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:26 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/08 16:03:56 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <sstream>

# define MSG_DEBUG "Two number 9s, a number 9 large, a number 6 with extra dip, a number 7, two number 45s, one with cheese, and a large soda.\n"
# define MSG_INFO "All you had to do was follow the damn train, CJ!\n"
# define MSG_WARNING "Ah shit, here we go again...\n"
# define MSG_ERROR "YOU picked the wrong house, fool!\n"
# define MSG_EMPTY "Wasted\n"

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Harl::*Functions[4])(void);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif