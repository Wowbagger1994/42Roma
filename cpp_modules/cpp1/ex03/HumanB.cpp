/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:05:51 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:42:47 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

void HumanB::attack()
{
	if (_weapon)
		std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
	else
		std::cout <<this-> _name << " attacks with their hands :(" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
