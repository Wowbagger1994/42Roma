/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:58:06 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:35:26 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string &Weapon::getType()
{
	return _type;
}
