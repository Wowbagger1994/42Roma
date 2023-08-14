/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:52:24 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("Darkness type") {
	return;
}


AMateria::AMateria(std::string const  &type): _type(type) {
	return;
}

AMateria::~AMateria() {
	return;
}

AMateria::AMateria(const AMateria &aMateria) {
	*this = aMateria;
	return;
}

AMateria  &AMateria::operator= (const AMateria &aMateria) {
	if (this != &aMateria) {
		_type = aMateria._type;
	}
	return (*this);
}

std::string const  &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* AMateria used on " << target.getName() << " *" << std::endl;
}
