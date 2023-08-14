/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:13:22 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:18:40 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie z0 = Zombie();
	Zombie z1 = Zombie("Gesù");
	Zombie *z2 = new Zombie("Giuseppe");
	Zombie *z3 = newZombie("Maria");

	z0.announce();
	z1.announce();
	(*z2).announce();
	z3->announce();

	randomChump("Zombieeeee");

	delete z2;
	delete z3;

	return 0;
}
