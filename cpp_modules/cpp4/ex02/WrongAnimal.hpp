/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:51:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {

protected:
	std::string _type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
    WrongAnimal (const WrongAnimal &wrongAnimal);
    WrongAnimal  &operator= (const WrongAnimal &wrongAnimal);

	std::string getType() const;
	void makeSound() const;
};

#endif

