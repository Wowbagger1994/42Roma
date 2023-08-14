/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:37:15 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 11:35:55 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	std::cout << " == CONSTRUCTORS == " << std::endl;
	ScavTrap a ("Ultron");
	ScavTrap b;
	ScavTrap c ("Thanos");

	std::cout << std::endl << " == A ACTIONS == " << std::endl;
	a.attack("Captain America");
	a.beRepaired(10);
	a.takeDamage(3);
	a.takeDamage(90);
	a.attack("Hulk");
	a.beRepaired(10);
	a.takeDamage(50);
	a.guardGate();

	std::cout << std::endl << " == B ACTIONS == " << std::endl;
	b.attack("Iron Man");
	b.takeDamage(90);
	b.beRepaired(200);
	b.takeDamage(15);
	b.attack("Thor");
	b.guardGate();
	b.guardGate();

	std::cout << std::endl << " == C ENERGY TEST == " << std::endl;
	for (int i = 0; i < 51; i++)
		c.attack("ENERGY TEST");
	c.guardGate();

	std::cout << std::endl << " == DESTRUCTORS == " << std::endl;

	return(0);

}
