/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:14:53 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/23 00:17:32 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

void testPoint (Point const a, Point const b, Point const c, Point const &pt, std::string msg) {
	std::cout << "(" << pt.getX().toFloat() << "," << pt.getY().toFloat() << ") "
		<< msg << " = " << (bsp(a, b, c, pt) ? "\033[1;32mINSIDE\033[0m" : "\033[1;31mOUTSIDE\033[0m") << std::endl;
}

int main(void) {

	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 30.0f);
	Point const c(20.0f, 0.0f);

	std::cout << std::endl << "Base triangle!" << std::endl;
	std::cout << "             B(10,30)       " << std::endl;
    std::cout << "            / \\			  " << std::endl;
    std::cout << "           /   \\           " << std::endl;
    std::cout << "          /     \\          " << std::endl;
    std::cout << "         /   .P  \\         " << std::endl;
    std::cout << "        /         \\        " << std::endl;
    std::cout << " A(0,0) ----------- C(20,0) " << std::endl;

	std::cout << std::endl << "=== TESTS ===" << std::endl;
	testPoint(a, b, c, Point(10, 15), "On the middle .P");
	testPoint(a, b, c, Point(0, 0), "On vertex A");
	testPoint(a, b, c, Point(10, 30), "On vertex B");
	testPoint(a, b, c, Point(20, 0), "On vertex C");
	testPoint(a, b, c, Point(10, 0), "On bottom edge");
	testPoint(a, b, c, Point(10.0f, -0.1f), "Right below bottom edge");
	testPoint(a, b, c, Point(10.0f, 0.1f), "Right above bottom edge");
	testPoint(a, b, c, Point(10.1f, 30.0f), "Close to vertex B (out)");
	testPoint(a, b, c, Point(10.0f, 29.9f), "Close to vertex B (in)");

	return 0;
}
