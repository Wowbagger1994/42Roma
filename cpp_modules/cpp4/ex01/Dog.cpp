/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:49:31 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[DOG] Default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	return;
}

Dog::~Dog() {
	std::cout << "[DOG] Destructor called" << std::endl;
	delete _brain;
	return;
}

Dog::Dog(const Dog &dog): Animal() {
	std::cout << "[DOG] Copy constructor called" << std::endl;
	*this = dog;
	return;
}

Dog  &Dog::operator= (const Dog &dog) {
	std::cout << "[DOG] Copy assignment operator called" << std::endl;
	if (this != &dog) {
		_type = dog._type;
		*_brain = *(dog._brain);
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Au Au... Auuuuuuuuuuuuuuuuuuuuuuu" << std::endl;
}

