/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:00:57 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/28 14:09:18 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define SEPARATOR "----------------------------------------"

// Because fuck the subject!!!
void addToTrash(AMateria* ptr, AMateria*** trash, int* size, int* capacity)
{
    if (!ptr)
        return;
    if (*size >= *capacity)
    {
        int newCapacity = (*capacity == 0) ? 16 : *capacity * 2;
        AMateria** newTrash = new AMateria*[newCapacity];
        for (int i = 0; i < *size; ++i)
            newTrash[i] = (*trash)[i];
        delete[] *trash;
        *trash = newTrash;
        *capacity = newCapacity;
    }
    (*trash)[(*size)++] = ptr;
}

int main()
{
	AMateria** trash = NULL;
	int trashSize = 0;
	int trashCapacity = 0;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	
	std::cout << SEPARATOR << std::endl;
	
	ICharacter *DeepCopy = new Character(*(Character*)me);
	
	std::cout << "\t\tDeepCopy uses 0's materia:" << std::endl;
	DeepCopy->use(0, *bob);
	std::cout << "\t\tDeepCopy throws away materia:" << std::endl;
	addToTrash(DeepCopy->getMateriaPtr(0), &trash, &trashSize, &trashCapacity);
	DeepCopy->unequip(0);
	std::cout << "\t\tMe still can use and uses 0's materia:" << std::endl;
	me->use(0, *bob);
	std::cout << "\t\tDeepCopy uses 0's materia again:" << std::endl;
	DeepCopy->use(0, *bob);
	
	std::cout << SEPARATOR << std::endl;
	std::cout << "\t\tAssignement verification" << std::endl;
	std::cout << "\t\tBob uses 0's materia: ";
	bob->use(0, *me);
	std::cout << std::endl;
	*static_cast<Character*>(bob) = *static_cast<Character*>(me);
	std::cout << "\t\tBob became Me!" << std::endl;
	std::cout << "\t\tBob uses 0's materia again: ";
	bob->use(0, *me);

	delete bob;
	delete me;
	delete src;
	delete DeepCopy;

	for (int i = 0; i < trashSize; ++i)
    	delete trash[i];
	delete[] trash;

	return 0;
}
