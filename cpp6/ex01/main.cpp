/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:45:42 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 16:51:14 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		*data = new Data;
	uintptr_t	raw;

	data->integer = 42;
	data->str = " Mulhouse";

	raw = Serializer::serialize(data);
	data = Serializer::deserialize(raw);
	std::cout << "Data integer: " << data->integer << std::endl;
	std::cout << "Data string: " << data->str << std::endl;
	delete data;
	return (0);
}
