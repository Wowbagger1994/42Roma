/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:39:38 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[CAT] Default constructor called" << std::endl;
	_type = "Cat";
	return;
}

Cat::~Cat() {
	std::cout << "[CAT] Destructor called" << std::endl;
	return;
}

Cat::Cat(const Cat &cat): Animal() {
	std::cout << "[CAT] Copy constructor called" << std::endl;
	*this = cat;
	return;
}

Cat  &Cat::operator= (const Cat &cat) {
	std::cout << "[CAT] Copy assignment operator called" << std::endl;
	if (this != &cat) {
		_type = cat._type;
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meeeeeeeeoooooowwwwwwwwnnnnnn" << std::endl;
}
