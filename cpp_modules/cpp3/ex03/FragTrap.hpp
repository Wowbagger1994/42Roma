/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:32:38 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/11 23:15:56 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

public:
	FragTrap();
	FragTrap(std::string const name);
	~FragTrap();
    FragTrap (const FragTrap &scavTrap);
    FragTrap  &operator= (const FragTrap &scavTrap);

	void highFivesGuys();
	void attack(const std::string &target);
};

#endif
