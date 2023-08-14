/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:27:18 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/11 23:18:35 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : _name("Anonymous")
{
	std::cout << "[DIAMONDTRAP] Default constructor called" << std::endl;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	return;
}

DiamondTrap::DiamondTrap(std::string const name) : _name(name)
{
	std::cout << "[DIAMONDTRAP] Default constructor with param called. New name: " << name << std::endl;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	return;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DIAMONDTRAP] Destructor called for " << _name << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap._name + "_clap_name"),
														   _name(diamondTrap._name)
{
	std::cout << "[DIAMONDTRAP] Copy constructor called" << std::endl;
	*this = diamondTrap;
	return;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout << "[DIAMONDTRAP] Copy assignment operator called" << std::endl;
	if (this != &diamondTrap)
	{
		_name = diamondTrap._name;
		ClapTrap::_name = _name + "_clap_name";
		_hitPoints = diamondTrap._hitPoints;
		_energyPoints = diamondTrap._energyPoints;
		_attackDamage = diamondTrap._attackDamage;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	if (_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << _name << " is already dead. Have you ever seen a dead DiamonTrap talking?" << std::endl;
		return;
	}
	std::cout << "My ClapTrap name is " << ClapTrap::_name << ", and my DiamondTrap name is " << _name << std::endl;
}
