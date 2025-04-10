/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_constructor_example.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:21:57 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 13:02:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

class Entity {
private:
	const int _id;              // const: must be initialized, can't be assigned

public:
	// Normal constructor
	Entity(int id) : _id(id) {
	}

	// ✅ COPY CONSTRUCTOR — correct version: member-by-member
	Entity(const Entity& other) : _id(other._id) {
		std::cout << "[Copy constructor called correctly]\n";
	}

	// Entity(const Entity& other) {
	// 	*this = other; // 💀 Ceci appelle operator= sur un objet non encore construit
	// }

	// ❌ BAD COPY (just for test): would fail if used in copy constructor
	Entity& operator=(const Entity& other) {
		std::cout << "[Assignment operator called]\n";
		if (this == &other) {
			return *this; // self-assignment check
		}
		// _id = other._id; // ❌ Error: cannot assign to const
		return *this;
	}

	void print() const {
		std::cout << "ID: " << _id  << std::endl;
	}
};

int main() {
	Entity a(42);
	Entity b = a; // 👈 appelle le constructeur de copie

	a.print();
	b.print();

	// Entity c(0, ""); c = a; // <- OK : utilise operator=
}

