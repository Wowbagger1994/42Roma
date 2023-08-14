/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:01:50 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 02:08:53 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main()
{
	std::cout << "\n===== RANDOM TESTS =====" << std::endl;
	for (int i = 0; i < 10; i++) {
		Base *ptr = generate();

		std::cout << "identify_ptr: ";
		identify(ptr);

		std::cout << "identify_ref: ";
		identify(*ptr);

		delete ptr;
	}

	std::cout << "\n===== ERROR TEST =====" << std::endl;

	std::cout << "identify_ptr: ";
	identify(0);

	std::cout << "identify_ref: ";
	identify(0);

	return (0);
}
