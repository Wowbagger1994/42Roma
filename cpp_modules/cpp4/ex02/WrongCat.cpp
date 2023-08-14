/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:51:24 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "[WRONG CAT] Default constructor called" << std::endl;
	_type = "WrongCat";
	return;
}

WrongCat::~WrongCat() {
	std::cout << "[WRONG CAT] Destructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &wrongCat): WrongAnimal() {
	std::cout << "[WRONG CAT] Copy constructor called" << std::endl;
	*this = wrongCat;
	return;
}

WrongCat  &WrongCat::operator= (const WrongCat &wrongCat) {
	std::cout << "[WRONG CAT] Copy assignment operator called" << std::endl;
	if (this != &wrongCat) {
		_type = wrongCat._type;
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat Meeeeeeeeoooooowwwwwwwwnnnnnn" << std::endl;
}
