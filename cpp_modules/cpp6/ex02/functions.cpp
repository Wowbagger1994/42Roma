/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:43:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 02:04:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void) {
	int r = std::rand() % 3;

	switch (r) {
	case 0:
		std::cout << "A done" << std::endl;
		return (new A());
	case 1:
		std::cout << "B done" << std::endl;
		return (new B());
	default:
		std::cout << "C done" << std::endl;
		return (new C());
	}
	return (0);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "?";
	std::cout << std::endl;
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}  catch (std::exception& e) {};
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception& e) {};
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}  catch (std::exception& e) {};

	std::cout << "?" << std::endl;
}
