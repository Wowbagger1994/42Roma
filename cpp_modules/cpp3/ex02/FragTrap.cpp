/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:32:33 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 11:58:49 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "[FRAGTRAP] Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name) {
	std::cout << "[FRAGTRAP] Default constructor with param called. New name: " << name << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return;
}

FragTrap::~FragTrap() {
	std::cout << "[FRAGTRAP] Destructor called for " << _name << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap &FragTrap): ClapTrap(FragTrap._name) {
	std::cout << "[FRAGTRAP] Copy constructor called" << std::endl;
	*this = FragTrap;
	return;
}

FragTrap  &FragTrap::operator= (const FragTrap &FragTrap) {
	std::cout << "[FRAGTRAP] Copy assignment operator called" << std::endl;
	if (this != &FragTrap) {
		_name = FragTrap._name;
		_hitPoints = FragTrap._hitPoints;
		_energyPoints = FragTrap._energyPoints;
		_attackDamage = FragTrap._attackDamage;
	}
	return (*this);
}

void FragTrap::highFivesGuys() {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " is asking for a friendly high five! 🖐️" << std::endl;
}
