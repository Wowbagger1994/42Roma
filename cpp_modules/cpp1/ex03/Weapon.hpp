/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:55:25 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:35:18 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CPP
#define WEAPON_CPP

#include <string>

class Weapon
{
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string type);
	const std::string &getType();
	void setType(std::string type);
};

#endif
