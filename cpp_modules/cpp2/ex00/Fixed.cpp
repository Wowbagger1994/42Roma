/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:35:13 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 04:15:20 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &fixedN)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedN;
}

Fixed &Fixed::operator=(const Fixed &fixedN)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixedN.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_n << Fixed::_fractBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_n = raw >> Fixed::_fractBits;
}
