/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:32:38 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

private:
	bool _isGuardingGate;

public:
	ScavTrap();
	ScavTrap(std::string const name);
	~ScavTrap();
	ScavTrap (const ScavTrap &scavTrap);
	ScavTrap  &operator= (const ScavTrap &scavTrap);

	void guardGate();
	void attack(const std::string &target);
};

#endif
