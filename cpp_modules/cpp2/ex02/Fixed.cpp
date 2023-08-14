/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:35:13 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 04:28:07 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixedN)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedN;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = n * (1 << Fixed::_fractBits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	float x = n * (1 << Fixed::_fractBits);
	this->_n = (int)roundf(x);
}

Fixed &Fixed::operator=(const Fixed &fixedN)
{
	if (this != &fixedN)
		this->setRawBits(fixedN.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_n << Fixed::_fractBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_n = raw >> Fixed::_fractBits;
}

float Fixed::toFloat(void) const
{
	return (float)this->_n / (1 << Fixed::_fractBits);
}

int Fixed::toInt(void) const
{
	return this->_n >> Fixed::_fractBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixedN)
{
	os << fixedN.toFloat();
	return os;
};

bool Fixed::operator<(const Fixed &fixedN) const
{
	return (getRawBits() < fixedN.getRawBits());
}

bool Fixed::operator>(const Fixed &fixedN) const
{
	return (getRawBits() > fixedN.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixedN) const
{
	return (getRawBits() <= fixedN.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixedN) const
{
	return (getRawBits() >= fixedN.getRawBits());
}

bool Fixed::operator==(const Fixed &fixedN) const
{
	return (getRawBits() == fixedN.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixedN) const
{
	return (getRawBits() != fixedN.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixedN) const
{
	return Fixed((this->toFloat() + fixedN.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixedN) const
{
	return Fixed((this->toFloat() - fixedN.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixedN) const
{
	return Fixed((this->toFloat() * fixedN.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixedN) const
{
	return Fixed((this->toFloat() / fixedN.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + (1 << Fixed::_fractBits));
	return *this;
}

Fixed Fixed::operator++(int n)
{
	Fixed fixedN = *this;

	n = (1 << Fixed::_fractBits);
	this->setRawBits(this->getRawBits() + n);
	return fixedN;
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - (1 << Fixed::_fractBits));
	return *this;
}

Fixed Fixed::operator--(int n)
{
	Fixed fixedN = *this;

	n = (1 << Fixed::_fractBits);
	this->setRawBits(this->getRawBits() - n);
	return fixedN;
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

Fixed Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

Fixed Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}
