/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:52:43 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	this->_type = "ice";
	return;
}

Ice::~Ice() {
	return;
}

Ice::Ice(const Ice &ice) : AMateria() {
	*this = ice;
	return;
}

Ice  &Ice::operator= (const Ice &ice) {
	if (this != &ice) {
		_type = ice._type;
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
