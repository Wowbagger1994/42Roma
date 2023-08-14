/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:35:13 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : n(0)
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

Fixed::Fixed (const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->n = n * (1 << Fixed::fractBits);
}

Fixed::Fixed (const float n)
{
	std::cout << "Float constructor called" << std::endl;
	float x = n * (1 << Fixed::fractBits);
	this->n = (int)roundf(x);
}

Fixed &Fixed::operator=(const Fixed &fixedN)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixedN.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->n << Fixed::fractBits;
}

void Fixed::setRawBits(int const raw)
{
	this->n = raw >> Fixed::fractBits;
}

float Fixed::toFloat( void ) const
{
	return (float)this->n / (1 << Fixed::fractBits);
}

int Fixed::toInt( void ) const
{
	return this->n >> Fixed::fractBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixedN)
{
	os << fixedN.toFloat();
	return os;
};
