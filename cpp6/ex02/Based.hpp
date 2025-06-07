/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Based.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:59:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 18:05:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASED_HPP
# define BASED_HPP
# include <iostream>
# include <cstdlib> // For rand() and srand()

/*

E-Z: 
https://fr.wikipedia.org/wiki/Dynamic_cast

*/


class Based
{
	public:
		virtual ~Based();
		std::string	msg();
};

// For the reasons of readability, the classes A, B, and C are defined in the same file.

class	A : public Based
{
	public:
		A();
		~A();
};

class	B : public Based
{
	public:
		B();
		~B();
};

class	C : public Based
{
	public:
		C();
		~C();
};

Based *generate(void);

void	identify(Based *p);
void	identify(Based &p);

#define AMENO "\nDori me"
#define AMENO_FULL "\nDori me\n" \
"Interimo, adapare\n" \
"Dori me\n" \
"Ameno, ameno\n" \
"Latire\n" \
"Latire mo\n" \
"Dori me\n" \
"Ameno\n" \
"Omenare imperavi ameno\n" \
"Dimere, dimere matiro\n" \
"Matiremo\n" \
"Ameno\n" \
"Ameno dore\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Ameno do, dori me reo\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Dori me a-\n" \
"Ameno\n" \
"Ome nare imperavi ameno\n" \
"Dimere, dimere, matiro\n" \
"Matiremo\n" \
"Ameno\n" \
"Ameno dore\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Ameno do, dori me reo\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Dori me\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"(Do-omine, do-omine, do-omine, do-omine, do-omine, do-omine)\n" \
"Ameno\n" \
"Ameno dore\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Ameno do, dori me reo\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Dori me do\n" \
"Ameno dore\n" \
"Ameno dori me\n" \
"Ameno dori me\n" \
"Ameno do, dori me reo\n" \
"Ameno dori me\n" \
"Ameno dori me"

#endif // BASED_HPP