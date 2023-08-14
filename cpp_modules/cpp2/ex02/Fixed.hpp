/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:24:46 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 04:26:52 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _n;
	static const int _fractBits = 8;
public:
	Fixed();
	Fixed (const Fixed &fixedN);
	Fixed (const int n);
	Fixed (const float n);
	~Fixed();

	Fixed &operator=(const Fixed &fixedN);
	bool operator<(const Fixed &fixedN) const;
	bool operator>(const Fixed &fixedN) const;
	bool operator<=(const Fixed &fixedN) const;
	bool operator>=(const Fixed &fixedN) const;
	bool operator==(const Fixed &fixedN) const;
	bool operator!=(const Fixed &fixedN) const;

	Fixed operator+(const Fixed &fixedN) const;
	Fixed operator-(const Fixed &fixedN) const;
	Fixed operator*(const Fixed &fixedN) const;
	Fixed operator/(const Fixed &fixedN) const;

	Fixed &operator++();
	Fixed operator++(int n);
	Fixed &operator--();
	Fixed operator--(int n);

	static Fixed &min(Fixed &n1, Fixed &n2);
	static Fixed min(const Fixed &n1, const Fixed &n2);
	static Fixed &max(Fixed &n1, Fixed &n2);
	static Fixed max(const Fixed &n1, const Fixed &n2);


	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixedN);

#endif
