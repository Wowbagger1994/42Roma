/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:59:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/08/18 18:10:54 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bure1;
	Bureaucrat bure2("Qui", 1);
	Bureaucrat bure3("Quo", 150);
	Bureaucrat bure4("Qua", 42);

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bure1 << std::endl;
	std::cout << bure2 << std::endl;
	std::cout << bure3 << std::endl;
	std::cout << bure4 << std::endl;

	std::cout << "\n===== ERROR's =====" << std::endl;
	try
	{
		bure4.decrementGrade();
		bure1.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		bure2.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bure5("Paperino", -50);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bure1 << std::endl;
	std::cout << bure2 << std::endl;
	std::cout << bure3 << std::endl;
	std::cout << bure4 << std::endl;

	std::cout << "\n===== END =====" << std::endl;
}
