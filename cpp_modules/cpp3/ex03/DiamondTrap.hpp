/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:21:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/11 23:20:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(std::string const name);
	~DiamondTrap();
	DiamondTrap (const DiamondTrap &diamondTrap);
	DiamondTrap  &operator= (const DiamondTrap &diamondTrap);

	void attack(const std::string &target);
	void whoAmI();
};

#endif
