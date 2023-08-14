/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:30:00 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 11:30:27 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
						_name("Anonymous"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const name):
						_name(name),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0) {
	std::cout << "Default constructor with param called. New name: " << name << std::endl;
	return;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for " << _name << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "Copy constructor called" << std::endl;
	*this = clapTrap;
	return;
}

ClapTrap  &ClapTrap::operator= (const ClapTrap &clapTrap) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clapTrap) {
		_name = clapTrap._name;
		_hitPoints = clapTrap._hitPoints;
		_energyPoints = clapTrap._energyPoints;
		_attackDamage = clapTrap._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap has no energy to attack. Good luck in the battle..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead. Stop doing that, it is not cool" << std::endl;
		return ;
	}
	std::cout << "Oh No! ClapTrap " << _name << " took " << amount << " of damage! And now it ";
	int temp = _hitPoints - amount;
	if (temp <= 0) {
		_hitPoints = 0;
		std::cout << "is dead! :(" << std::endl;
		return ;
	}
	_hitPoints = temp;
	std::cout << "has only " << _hitPoints << " left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead. Repair is not the same as resurrection!" << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap has no energy to repair. It will be a problem..." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;

	std::cout << "ClapTrap " << _name << " repaired itself with " << amount << " hit points! "
	<< "Now it has " << _hitPoints << ", cool!" << std::endl;
}
