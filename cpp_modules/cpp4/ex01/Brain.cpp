/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:49:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[BRAIN] Default constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++)
		_ideas[i] = "Have no idea!";
	return;
}

Brain::~Brain() {
	std::cout << "[BRAIN] Destructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &brain) {
	std::cout << "[BRAIN] Copy constructor called" << std::endl;
	*this = brain;
	return;
}

Brain  &Brain::operator= (const Brain &brain) {
	std::cout << "[BRAIN] Copy assignment operator called" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < MAX_IDEAS; i++)
			_ideas[i] = brain._ideas[i];
	}
	return (*this);
}

