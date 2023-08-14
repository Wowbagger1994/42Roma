/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:24:46 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 04:15:00 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _n;
	static const int _fractBits = 8;
public:
	Fixed();
	Fixed (const Fixed &fixedN);
	~Fixed();
	Fixed &operator=(const Fixed &fixedN);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
