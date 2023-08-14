/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:13:22 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:20:39 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombies = zombieHorde(5, "Gesù");

	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
