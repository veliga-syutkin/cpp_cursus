/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Based.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:02:53 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 17:46:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Based.hpp"

Based::~Based() { std::cout << "Based destructor called" << std::endl; }

std::string	Based::msg()
{
	//system(xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ); // for the lulz
	return (AMENO);
}

A::A() { std::cout << "A constructor called" << std::endl; }
A::~A() { std::cout << "A destructor called" << std::endl; }

B::B() { std::cout << "B constructor called" << std::endl; }
B::~B() { std::cout << "B destructor called" << std::endl; }

C::C() { std::cout << "C constructor called" << std::endl; }
C::~C() { std::cout << "C destructor called" << std::endl; }

Based *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Based *p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "Type is A" << a->msg() << std::endl;
		return;
	}
	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "Type is B" << b->msg() << std::endl;
		return;
	}
	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "Type is C" << c->msg() << std::endl;
		return;
	}
}

/* <typeinfo> ? 
   what <typeinfo> ?
   is that a cheese? 
*/
void identify(Based &p)
{
	try // is it A?
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Type is A" << a.msg() << std::endl;
	}
	catch (...) // IT IS NOT A!
	{
		try // is it B then?
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "Type is B" << b.msg() << std::endl;
		}
		catch (...) // IT IS NOT B EITHER!
		{
			try // it must be C then
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "Type is C" << c.msg() << std::endl;
			}
			catch (...) // IT IS NOT C EITHER...
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
	
/* 
For the purists:
*/
// void identify(Based &p)
// {
// 	std::cout << "Identifying type of Based reference:" << std::endl;
// 	A *a = dynamic_cast<A*>(&p);
// 	if (a)
// 	{
// 		std::cout << "Type is A" << a->msg() << std::endl;
// 		return;
// 	}
// 	B *b = dynamic_cast<B*>(&p);
// 	if (b)
// 	{
// 		std::cout << "Type is B" << b->msg() << std::endl;
// 		return;
// 	}
// 	C *c = dynamic_cast<C*>(&p);
// 	if (c)
// 	{
// 		std::cout << "Type is C" << c->msg() << std::endl;
// 		return;
// 	}
// 	std::cout << "Unknown type" << std::endl;
// }
