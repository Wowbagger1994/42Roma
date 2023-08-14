/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:09:34 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 01:31:13 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Caster.hpp"

int main (int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: Program should receive 1 argument!" << std::endl;
		return (1);
	}

	Caster caster(argv[1]);
	caster.printConversions();

	return (0);
}
