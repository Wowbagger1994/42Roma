/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:52:37 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	this->_type = "cure";
	return;
}

Cure::~Cure() {
	return;
}

Cure::Cure(const Cure &cure) : AMateria() {
	*this = cure;
	return;
}

Cure  &Cure::operator= (const Cure &cure) {
	if (this != &cure) {
		_type = cure._type;
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* shoots an cure bolt at " << target.getName() << " *" << std::endl;
}
