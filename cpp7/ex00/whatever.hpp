/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:22:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 18:35:08 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // replace #ifndef/#define/#endif with #pragma once

template <typename T>
void swap(T &a, T &b) 
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
T min(T &a, T &b)
{
	return (a > b ? b : a); // (condition ? true_value : false_value)
}

template <typename T>
T max(T &a, T &b)
{
	return (a < b ? b : a); // (condition ? true_value : false_value)
}