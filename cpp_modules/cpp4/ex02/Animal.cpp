/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:50:27 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Raw Animal") {
	std::cout << "[ANIMAL] Default constructor called" << std::endl;
	return;
}

Animal::~Animal() {
	std::cout << "[ANIMAL] Destructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &animal) {
	std::cout << "[ANIMAL] Copy constructor called" << std::endl;
	*this = animal;
	return;
}

Animal  &Animal::operator= (const Animal &animal) {
	std::cout << "[ANIMAL] Copy assignment operator called" << std::endl;
	if (this != &animal) {
		_type = animal._type;
	}
	return (*this);
}

std::string Animal::getType() const {
	return (this->_type);
}

void Animal::makeSound() const {
	std::cout << "Raaaaaawwwnn" << std::endl;
}
