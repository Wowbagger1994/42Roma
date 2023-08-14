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

Fixed::Fixed()
{
	n = 0;
}

Fixed::~Fixed(){}

Fixed::Fixed (const Fixed &fixedN)
{
	*this = fixedN;
}

Fixed::Fixed (const int n)
{
	this->n = n * (1 << Fixed::fractBits);
}

Fixed::Fixed (const float n)
{
	float x = n * (1 << Fixed::fractBits);
	this->n = (int)roundf(x);
}

Fixed &Fixed::operator=(const Fixed &fixedN)
{
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
	this->setRawBits(this->getRawBits() + (1 << Fixed::fractBits));
	return *this;
}

Fixed Fixed::operator++(int n)
{
	Fixed fixedN = *this;

	n = (1 << Fixed::fractBits);
	this->setRawBits(this->getRawBits() + n);
	return fixedN;
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - (1 << Fixed::fractBits));
	return *this;
}

Fixed Fixed::operator--(int n)
{
	Fixed fixedN = *this;

	n = (1 << Fixed::fractBits);
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

