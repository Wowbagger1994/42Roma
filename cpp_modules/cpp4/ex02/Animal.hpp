/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:50:31 by ebraho            #+#    #+#             */
/*   Updated: 2022/08/11 04:14:48 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

protected:
	std::string _type;
	Animal();
    Animal  &operator= (const Animal &animal);
    Animal (const Animal &animal);

public:
	virtual ~Animal() = 0;

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif

