/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:37:15 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 11:33:06 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << " == CONSTRUCTORS == " << std::endl;
	ClapTrap a("Ultron");
	ClapTrap b;
	ClapTrap *c = new ClapTrap("Thanos");

	std::cout << std::endl << " == A ACTIONS == " << std::endl;
	a.attack("Captain America");
	a.beRepaired(4);
	a.takeDamage(3);
	a.takeDamage(30);
	a.attack("Hulk");
	a.beRepaired(10);
	a.takeDamage(50);

	std::cout << std::endl << " == B ACTIONS == " << std::endl;
	b.attack("Iron Man");
	b.takeDamage(9);
	b.beRepaired(2);
	b.takeDamage(3);
	b.attack("Thor");

	std::cout << std::endl << " == C ACTIONS (NO ENERGY) == " << std::endl;
	for (int i = 0; i < 11; i++)
		c->attack("Some target...");


	std::cout << std::endl << " == DESTRUCTORS == " << std::endl;
	delete c;
	return(0);

}
